#include <bits/stdc++.h>
using namespace std;
const string TASKNAME = "baiD";  //ten bai`
typedef long long ll;
typedef pair<int, int> ptq;

const int iFirst = 6;
const int iLast = 10;

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

string intToString(int x)
{
    stringstream ss;
    ss << x;
    string st; ss >> st;
    if (x < 10) st = "0" + st;
    if (x == 0) st = "00";
    return st;
}


void MakeTest(ofstream& cout, int iTest)  // ham sinh test
{
    srand(time(NULL));
    int n = rand()%(10000-200) + 200;
    cout << n << '\n';
    for (int i = 1; i <= n; i++)
        cout << rand() << ' ';
}
int main()
{
    srand(time(NULL));

    system(("mkdir " + TASKNAME).c_str());

    for(int iTest = iFirst; iTest <= iLast; iTest++)
    {
        string testForder = TASKNAME + "\\Test" + intToString(iTest); //ten folder SUM\\Test
        string inputFile = TASKNAME + ".INP";
        string outputFile = TASKNAME + ".OUT";

        system(("mkdir " + testForder).c_str());

        ofstream inp (inputFile.c_str());

        MakeTest(inp, iTest);
        inp.close();

        system((TASKNAME + ".exe").c_str());  // bat buoc phai co file (TASKNAME + ".exe") thi chuong trinh moi chay duoc

        system(("move /y " + inputFile + " " + testForder + "/" + inputFile).c_str());
        system(("move /y " + outputFile + " " + testForder + "/" + outputFile).c_str());
    }
}
