#include<iostream>
#include<bitset>
#include<iomanip>
#include<string>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<cmath>

using namespace std;

//const int input = 3; // for 3x3 reversible conservative function
//const int noCombi = static_cast<int>(pow(2, input)); //# of combination = 8

//this function generates all different functions by combining the ..
//..positions where the number of 1 is 1
//this functions generates 3! = 6 different functions.

void printOne(int outputNumbers[], int allOnes[], int n, int noCombi,
	      int onesCombined[][8])
{
   static int row = 0;
   //static int num = 1;
   //ostringstream fileName;
   for(int i = 0; i < n; i++)
   {
      outputNumbers[static_cast<int>(pow(2,i))] = allOnes[i];
   }

   cout << "[" << row << "] ";
   //fileName << "crf3x3One_" << num << ".txt";
   //ofstream out(fileName.str().c_str(), ios::trunc|ios::out);
   for(int col = 0; col < noCombi; col++)
   {
      //int bitArray[8];
      onesCombined[row][col] = outputNumbers[col];
      //bitArray[col] = onesCombined[row][col];
      //string bin = bitset<3>(bitArray[col]).to_string();
      //cout << bin << " ";
      //out << bin << " ";
      //out << onesCombined[row][col] << " ";
      cout << onesCombined[row][col] << " ";
    }
   //num++;
   row++;
   cout << endl;
}

//this function generates all different functions by combining the ..
//..positions where the number of 1 is 2
//this function generates 3! = 6 different functions
void printTwo(int outputNumbers[], int allTwos[], int n, int noCombi,
	      int twosCombined[][8])
{
   static int row = 0;
   //static int num = 1;
   //ostringstream fileName;
   for(int i = 0; i < n; i++)
   {
      if(i == 0)
	 outputNumbers[3] = allTwos[i];
      else
	 outputNumbers[i+4] = allTwos[i];
   }
   cout << "[" << row << "] ";
   //fileName << "crf3x3Two_" << num << ".txt";
   //ofstream out(fileName.str().c_str(), ios::trunc|ios::out);
   for(int col = 0; col < noCombi; col++)
   {
      //int bitArray[8];
      twosCombined[row][col] = outputNumbers[col];
      //bitArray[col] = twosCombined[row][col];
       //string bin = bitset<3>(bitArray[col]).to_string();
       //cout << bin << " ";
       //out << bin << endl;
       //out << twosCombined[row][col] << " ";
      cout << twosCombined[row][col] << " ";
   }
   //num++;
   row++;
   cout << endl;
}


//this function print the final conservative reversible functions to the files
void writeToFile(int noCombi, int onesTwosCombined[][8], int num)
{
    ostringstream fileName;
    fileName << "crf3x3OneTwo_" << num << ".txt";
    ofstream out(fileName.str().c_str(), ios::trunc|ios::out);
    cout << "[" << num << "] " ;
    for(int col = 0; col < noCombi; col++)
    {
       string bin = bitset<3>(onesTwosCombined[num][col]).to_string();
       out << bin << endl;
       //out << onesTwosCombined[num][col] << endl;
       cout << onesTwosCombined[num][col] << " ";
    }

}


//this function generates all different functions by combining the ..
//..positions where the number of 1 is 1 and 2
//this function generates 6 x 6 = 36 reversible conservative functions
void printOnesTwos(int onesCombined[][8], int twosCombined[][8],
		   int noFunc12, int noCombi, int onesTwosCombined[][8])
{
   int row = 0;
   for(int i = 0; i < noFunc12; i++)
   {
      for(int j = 0; j < noFunc12; j++)
      {
	 //cout << "[" << row << "] ";
	 for(int col = 0; col < noCombi; col++)
	 {
	    if(col == 0 || col == 1 || col == 2 || col == 4 || col == 7)
	       onesTwosCombined[row][col] = onesCombined[i][col];
	    if(col == 3 || col == 5 || col == 6)
	       onesTwosCombined[row][col] = twosCombined[j][col];
	    //cout << onesTwosCombined[row][col];
	    // string bin = bitset<3>(onesTwosCombined[row][col]).to_string();
	    //cout << bin << " ";
	 }
	 writeToFile(noCombi, onesTwosCombined, row);
	 cout << endl;
	 row ++;
      }
   }
}

int main()
{
   int input = 3; // for 3x3 reversible conservative function
   int noCombi = static_cast<int>(pow(2, input)); //# of combination = 8
   const int noPos12 = 3; //# of positions where # of 1 is 1 & 2 is 3
   const int noFunc12 = tgamma(noPos12+1); // 3! = 6 [6 possible functions]
   const int totalFunc = 36; // 3!x3! = 36 functions in total
   //int allOnes[3], outputNumbers[8], allTwos[3];
   int outputNumbers[noCombi];
   int onesCombined[noFunc12][8], twosCombined[noFunc12][8], onesTwosCombined[totalFunc][8];
   //int onesCombined[6][noCombi], twosCombined[6][8], onesTwosCombined[36][8];
   //int onesCombined[noFunc12][noCombi], twosCombined[noFunc12][noCombi];
   //int onesTwosCombined[totalFunc][noCombi];
   int temp, temp2;
   int n;
   for( int i = 0; i < noCombi; i++)
      outputNumbers[i] = i;
   cout << endl;

   //n = 3;

   int allOnes[] = {1, 2, 4};
   // allOnes[1] = 2;
   //allOnes[2] = 4;
   int allTwos[] = {3, 5, 6};
   //allTwos[0] = 3;
   //allTwos[1] = 5;
   //allTwos[2] = 6;
   for(int j = 1; j <= input; j++)
   {
      for(int i = 0; i < input-1; i++)
      {
	 temp =  allOnes[i];
	 allOnes[i] =  allOnes[i+1];
	 allOnes[i+1] = temp;
	 printOne(outputNumbers, allOnes, noPos12, noCombi, onesCombined);
      }
   }

   cout << endl;
   for( int i = 0; i < noCombi; i++)
      outputNumbers[i] = i;

     for(int j = 1; j <= input; j++)
     {
	for(int i = 0; i < input-1; i++)
	{
	   temp2 = allTwos[i];
	   allTwos[i] = allTwos[i+1];
	   allTwos[i+1] = temp2;
	   printTwo(outputNumbers, allTwos, noPos12, noCombi, twosCombined);
	}
     }

     cout << endl;
     printOnesTwos(onesCombined, twosCombined, noFunc12, noCombi, onesTwosCombined);
     return 0;
}

