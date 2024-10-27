#! /bin/perl6

sub mktest(Str $num) {
    chars($num) ~ "\n" ~ (join " ", $num.comb) ~ "\n";
}

sub randtest(Int $len) {
    join "", map(-> $x {Str((^10).pick)}, 1..$len);
}

sub nochange_a(Int $len) {
    my $curr = 10;
    my $cnt = 0;
    my @res = ();
    my $k = $len div 20 + 1;
    for 1..$len {
        if $curr > 0 && $cnt <= 0 {
            $cnt = $len div $curr;
            $cnt += (-$k..$k).pick;
            $curr--;
        }
        @res.push($curr);
        $cnt--;
    }
    @res;
}

sub nochange(Int $len) {
    join "", nochange_a($len);
}

sub fixed(Int $len, ($a, $b)) {
    my @res = nochange_a($len);
    die "Canot swap res[$a] = @res[$a], res[$b] = @res[$b]" if @res[$a] == @res[$b];
    @res[$a,$b] = @res[$b,$a];
    join "", @res;
}

my $dir = "testcases";
shell "mkdir -p $dir";

srand(94360348);

# sample tests

spurt "$dir/01.in", mktest("825");
spurt "$dir/02.in", mktest("63");

# subtask 1: 10 <= X < 100

spurt "$dir/03.in", mktest("94");
spurt "$dir/04.in", mktest("18");

# subtask 2: X < 10^9

spurt "$dir/05.in", mktest("4294383");
spurt "$dir/06.in", mktest("875432");
spurt "$dir/07.in", mktest("8754432");
spurt "$dir/08.in", mktest("77777777");
spurt "$dir/09.in", mktest("98765342");
spurt "$dir/10.in", mktest("98884221");

# subtask 3: X <= 4*10^18

spurt "$dir/11.in", mktest("9923974392029");
spurt "$dir/12.in", mktest("99999999998866211");
spurt "$dir/13.in", mktest("910000000000090000");
spurt "$dir/14.in", mktest("9573452883424535643");

# subtask 4: n <= 1000

spurt "$dir/15.in", mktest(randtest(999));
spurt "$dir/16.in", mktest(fixed(990, (828, 893)));
spurt "$dir/17.in", mktest(nochange(1000));
spurt "$dir/18.in", mktest(fixed(998, (20, 798)));

# subtask 5: n <= 10^6

spurt "$dir/19.in", mktest((join "", map(-> $x {"9"}, 1..30000)) ~ randtest(999989-30000));
spurt "$dir/20.in", mktest(fixed(1000000, (999876, 721333)));
spurt "$dir/21.in", mktest(nochange(1000000));
spurt "$dir/22.in", mktest(fixed(1000000, (300000, 600000)));

