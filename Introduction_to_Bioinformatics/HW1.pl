
my %codeTable =("UUU","F","UUC","F","UUA","L","UUG","L","UCU","S","UCC","S","UCA","S","UCG","S","UAU","Y","UAC","Y","UAA"," STOP ","UAG"," STOP ","UGU","C","UGC"
    ,"C","UGA"," STOP ","UGG","W","CUU","L","CUC","L","CUA","L","CUG","L","CCU","P","CCC","P","CCA","P","CCG","P","CAU","H","CAC","H","CAA","Q","CAG","Q","CGU"
    ,"R","CGC","R","CGA","R","CGG","R","AUU","I","AUC","I","AUA","I","AUG","M","ACU","T","ACC","T","ACA","T","ACG","T","AAU","N","AAC","N","AAA","K","AAG","K"
    ,"AGU","S","AGC","S","AGA","R","AGG","R","GUU","V","GUC","V","GUA","V","GUG","V","GCU","A","GCC","A","GCA","A","GCG","A","GAU","D","GAC","D","GAA","E","GAG"
    ,"E","GGU","G","GGC","G","GGA","G","GGG","G");

my $x = "";
my $mRNA = "";
my $aminoAcid = "";
my $flag = 0;
my @key = keys %codeTable;
my @value = values %codeTable;
my $size = @key;
my $inputDNA = "TCATAATACGTTTTGTATTCGCCAGCGCTTCGGTGT";
my $choose = 0;

print "input DNA: $inputDNA\n";

print "If you want to change the DNA, press 1, if not, press any key.\n";
$choose = <STDIN>;
if($choose == 1){
    $inputDNA = <STDIN>;
}

$inputDNA = uc($inputDNA);

for($i=0; $i<length($inputDNA); $i++){
    $x = substr($inputDNA,$i,1);
    if($x eq "T"){
        $mRNA .= "A";
    }
    elsif($x eq "C"){
        $mRNA .= "G";
    }
    elsif($x eq "A"){
        $mRNA .= "U";
    }
    elsif($x eq "G"){
        $mRNA .= "C";
    }
    
    $j = 0;
    $flag = 0;
    while($i%3 == 2 && $flag == 0 && $j < $size){
        $x = substr($mRNA,$i-2,3);
        if($x eq $key[$j]){
            $aminoAcid .= $value[$j];
            $flag = 1;
        }
        $j++;
    }
}
print "translation to mRNA: $mRNA\n";
print "translation to aminoAcid: $aminoAcid \n";
