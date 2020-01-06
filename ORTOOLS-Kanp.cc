#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <time.h>
#include <chrono>
#include <queue>
#include "../include/ortools/algorithms/knapsack_solver.h"

using namespace std;

// OR-TOOLS - - - - - - - - - - - - - - - - - - - - - - - - -

namespace operations_research
{

int KnapsackExample(int m,int p,int v[],int w[])
{
    KnapsackSolver solver(KnapsackSolver::KNAPSACK_DYNAMIC_PROGRAMMING_SOLVER,
                          "SimpleKnapsackExample");
    std::vector<int64> values ;
    std::vector<int64> we1 ;
    std::vector<std::vector<int64>> weights;
    std::vector<int64> capacities ;

for (int i = 0; i < p; i++)
    {
        values.push_back(v[i]);
        we1.push_back(w[i]);
        weights = { we1 };
        capacities.push_back(m);
    }

    solver.Init(values, weights, capacities);
    int64 computed_value = solver.Solve();

    return computed_value ;
}
}

// MAIN - - - - - - - - - - - - - - - - - -- - - - - - -- - 

int main() {
        int i,n,s[5000],v[5000],w[5000];
        int m,p;
  
    ifstream fileC;
    ofstream outfile;
    outfile.open("or-results.csv");
   
        outfile<<"      problem_id       "<<'\t'<<'\t'<<"orkn"<<'\t'<<"time-or"<<endl;
for (int nn : {10,50,100,500}){
        for (int rr : {50,100,500,1000}) {
                for (int type : {1,2,3,4}) {
                        for (int id=1; id<=5;id++)
                        {
                        string filename="problem_"+to_string(nn)+"_" +to_string(rr)+"_"+to_string(type)+"_"+to_string(id)+"_5.txt";
    fileC.open(filename.c_str());

                if (fileC.is_open()){
        fileC>>p;
        for (i=0;i<p;i++)
        fileC>>s[i]>>v[i]>>w[i];
        }
        fileC>>m;
        fileC.close();
        outfile<< filename << '\t' << '\t';
        
        
        auto start5 = chrono::steady_clock::now();
        double clStart5 = clock();
        outfile << operations_research::KnapsackExample(m, p, v, w);
        auto end5 = chrono::steady_clock::now();
        double clEnd5 = clock();
        auto difTime5 = end5 - start5;
        double diff5 = chrono::duration <double, nano>(difTime5).count();
        double diffTicks5 = clEnd5 - clStart5;
        outfile << '\t' << diffTicks5 << '\t' << endl;

}}}}

        return 0;
}
