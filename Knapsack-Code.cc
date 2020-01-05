#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <time.h>
#include <chrono>
#include <queue>

using namespace std;


// DYNAMIC  - - - - - - - - - - - - - - - - - - - - - -

int dynamic(int m, int p, int w[], int v[])
{
int dp[m+1];
int solve();

    memset(dp, 0, sizeof(dp));
    for(int i =1; i <= p; i++) {
        for(int j = m; j >= w[i]; j--) {
             dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
    }
    return dp[m];
}

// GREEDY - - - - - - - - - - - - - - - - - - - - - -

int greedy(int m, int v[], int w[], int p , int s[])
{
    int x[500];
    float ratio[500]; 
    float totalprofit;
    float y;
    int temp;
    int i,j;
    y=m;
    totalprofit=0;

for (i = 0; i < p; i++) {
      ratio[i] = v[i] / w[i];
   }
 
   for (i = 0; i < p; i++) {
      for (j = i + 1; j < p; j++) {
         if (ratio[i] < ratio[j]) {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;
 
            temp = w[j];
            w[j] = w[i];
            w[i] = temp;
 
            temp = v[j];
            v[j] = v[i];
            v[i] = temp;
        temp=s[j];
        s[j]=s[i];
        s[i]=temp;

         }
      }
   }

    for(i=0;i < p;i++)
        x[i]=0.0;
    for(i=0;i < p;i++)
    {
        if(w[i] > y)
            break;
        else
        {
            x[i]=1.0;
            totalprofit=totalprofit+v[i];
            y=y-w[i];
        }
    }
    if(i < p)   
        x[i]=y/w[i];
    totalprofit=totalprofit+(x[i]*v[i]);
    return totalprofit;          
}

// BRUTE FORCE - - - - - - - - - - - - - - - - - - - - - -

int bruteforce(int v[], int w[], int p, int m)
{
    float nowtime;
    nowtime=clock();
    int *A = (int *) calloc(p, sizeof(int));
    int i;
    int val=0;

    for (i = 0; ; i++) {
        int j = p;
        int tempWeight = 0;
        int tempValue = 0;
        int k;

        k = 1;
        for (j = 0; j < p; j++) {
            A[j] += k;

            k = A[j] / 2;
            A[j] = A[j] % 2;
    if ((clock()-nowtime)/CLOCKS_PER_SEC>=10)  // Break code after 10 secs
        break;
        }
        
        if (k) break;

        for (k = 0; k < p; k++) {
            if (A[k] == 1) {
                tempWeight = tempWeight + w[k];
                tempValue = tempValue + v[k];

            }
        }
        if (tempValue > val && tempWeight <= m) {
            val = tempValue;
        }
}
    free(A);
    return val;
}


// BRANCH AND BOUND - - - - - - - - - - - - - - - - - - - - - 

struct node
{
    int level;
    int profit;
    int weight;
    int bound;
};

int bound(node u, int p, int m, vector<int> pVa, vector<int> wVa)
{
    int j = 0, k = 0;
    int totweight = 0;
    int result = 0;

    if (u.weight >= m)
    {
        return 0;
    }
    else
    {
        result = u.profit;
        j = u.level + 1;
        totweight = u.weight;

        while ((j < p) && (totweight + wVa[j] <= m))
        {
            totweight = totweight + wVa[j];
            result = result + pVa[j];
            j++;
        }

        k = j;

        if (k < p)
        {
            result = result + (m - totweight) * pVa[k]/wVa[k];
        }
        return result;
    }
}

int branchandbound(int p, int v[], int w[], int m)
{
    queue<node> Q;
    node u, n;
    vector<int> pV;
    vector<int> wV;
    Q.empty();

    for (int i = 0; i < p; i++)
    {
        pV.push_back(v[i]);
        wV.push_back(w[i]);
    }

    n.level = -1;
    n.profit = 0;
    n.weight = 0;

    int maxProfit = 0;

    n.bound = bound(n, p, m, pV, wV);
    Q.push(n);

    while (!Q.empty())
    {
        n = Q.front();
        Q.pop();

        if (n.level == -1)
        {
            u.level = 0;
        }
        else if (n.level != (p - 1))
        {
            u.level = n.level + 1;
        }

        u.weight = n.weight + w[u.level];
        u.profit = n.profit + v[u.level];
        u.bound = bound(u, p, m, pV, wV);

        if (u.weight <= m && u.profit > maxProfit)
        {
            maxProfit = u.profit;
        }

        if (u.bound > maxProfit)
                                          
   {
            Q.push(u);
        }
    }
    return maxProfit;
}


// MAIN Function - - - - - - - - - - - - - - - - - - - - - -

int main() 
{
	int i, n, s[5000], v[5000], w[5000];
	int m, p;

    string name ;
    ifstream fileC;
    ofstream outfile;
    outfile.open("results.csv");

	outfile<<"      problem_id       "<<'\t'<<'\t'<<"dp"<<'\t'<<"time-dp"<<'\t'<<"gr"<<'\t'<<"time-gr"<<'\t'<<"bf"

                                                 <<'\t'<<"time-bf"<<'\t'<<"bb"<<'\t'<<"time-bb"<<endl;
for (int nn : {10,50,100,500}){ 
	for (int rr : {50,100,500,1000}) {
		for (int type : {1,2,3,4}) {
			for (int id=1; id<=5; id++) 
			{
			string filename="problem_"+to_string(nn)+"_" +to_string(rr)+"_"+to_string(type)+"_"+to_string(id)+"_5.txt";
    		fileC.open(filename.c_str());
			if (fileC.is_open()){
			   fileC>>p;
			   for (i=0; i<p; i++)	
			   fileC>>s[i]>>v[i]>>w[i];
			}
	
	fileC>>m;
	fileC.close();


// Dynamic Time Count and Function Call 
auto start = chrono::steady_clock::now();
double clStart = clock();
outfile<<filename<<'\t'<<'\t';
outfile<<dynamic(m, p, w, v)<<'\t';
auto end = chrono::steady_clock::now();
double clEnd = clock();
auto difTime = end-start;
double diff = chrono::duration <double,nano> (difTime).count();
double diffTicks = clEnd-clStart;
outfile <<diffTicks <<'\t';


// Greedy Time Count and Function Call
auto start2 = chrono::steady_clock::now();
double clStart2 = clock();
outfile<<greedy(m, v, w, p, s);  
auto end2 = chrono::steady_clock::now();
double clEnd2 = clock();
auto difTime2 = end2-start2;
double diff2 = chrono::duration <double,nano> (difTime2).count();
double diffTicks2 = clEnd2-clStart2;
outfile <<'\t'<<diffTicks2 <<'\t';


// Brute Force Time Count and Function Call
auto start3 = chrono::steady_clock::now();
double clStart3 = clock();
outfile<<bruteforce(v, w, p, m);
auto end3 = chrono::steady_clock::now();
double clEnd3 = clock();
auto difTime3 = end3-start3;
double diff3 = chrono::duration <double,nano> (difTime3).count();
double diffTicks3 = clEnd3-clStart3;
outfile <<'\t'<<diffTicks3 <<'\t';


// Branch and Bound Time Count and Function Call
auto start4 = chrono::steady_clock::now();
double clStart4 = clock();
outfile<<branchandbound( p, v, w, m)<<'\t';
auto end4 = chrono::steady_clock::now();
double clEnd4 = clock();
auto difTime4 = end4-start4;
double diff4 = chrono::duration <double,nano> (difTime4).count();
double diffTicks4 = clEnd4-clStart4;
outfile <<diffTicks4 <<'\t'<<endl;


}}}}
outfile.close();
return 0;
}
