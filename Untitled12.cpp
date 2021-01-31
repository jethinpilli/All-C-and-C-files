# include <iostream>
# include <fstream>
# include <vector>

Namespace STD using;

Sort long (vector<int>&, int, int);
Partition int (vector<int>&, int, int);
Median_of_3 int (vector<int>&, int, int, int);

Main int (argc int, argv char**) {

Num vector<int>;

Store the elements in TXT file * into num vector * /
Infile ifstream;
Infile.open ("QuickSort.txt", ios:: in);
TMP int;
While (infile) TMP
Num.push_back (TMP);
Infile.close ();

Start sorting / * * /
CNT long = sort (Num, 0, num.size () -1);

For (I int = 0; num.size < I (); ++i)
Num[i] "endl" cout;
"Cout" # of comparisons: "" CNT "endl;

Return 0;
}

Sort long (Num vector<int>&, low int, high int) {

If (high low)
Return 0;
Pivot int = partition (Num, low, high);
Tmp1 long = sort (Num, low, pivot-1);
Tmp2 long = sort (Num, pivot+1, high);
Return (tmp1+tmp2+ (high-low));
}

Partition int (Num vector<int>&, low int, high int) {

Index int = median_of_3 (Num, low, high, (low+high) /2) ();
Pivot int = num[index];
Swap (num[low], num[index]);
I int = Low + 1;
Int j;
For (J = Low + 1; J < high; ++j) {
If (num[j] < pivot) {
Swap (num[i], num[j]);
++i;
}
Else do nothing / * * /
}
Swap (num[i-1], num[low]);
Return (i-1);
}

Median_of_3 int (Num vector<int>&, low int, high int, medium int) {

If (num[low] > max (num[medium], num[high])) {
If (num[high] > num[medium])
Medium return;
Else
High return;
}
If else (num[low] < min (num[medium], num[high])) {
If (num[high] > num[medium])
High return;
Else
Medium return;
}
Else
Low return;
}

