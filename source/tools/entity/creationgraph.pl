use strict;
use warnings;

use Entity;

my @files = Entity::find_entities();

open my $g, '>', 'creation.dot' or die $!;
print $g "digraph G {\n";

for my $f (sort @files) {
    next if $f =~ /^template_/;
    print "# $f...\n";
    my $ent = Entity::load_inherited($f);

    if ($ent->{Entity}{Builder}) {
        my $ents = $ent->{Entity}{Builder}{Entities}{' content'};
        $ents =~ s/\{civ\}/$ent->{Entity}{Identity}{Civ}{' content'}/eg;
        for my $b (split /\s+/, $ents) {
            print $g qq{"$f b" -> "$b b" [color=green];\n};
        }
    }

    if ($ent->{Entity}{TrainingQueue}) {
        my $ents = $ent->{Entity}{TrainingQueue}{Entities}{' content'};
        $ents =~ s/\{civ\}/$ent->{Entity}{Identity}{Civ}{' content'}/eg;
        for my $b (split /\s+/, $ents) {
            print $g qq{"$f t" -> "$b t" [color=blue];\n};
        }
    }
}

print $g "}\n";

close $g;

system("dot -Tpng creation.dot -o creation.png");
