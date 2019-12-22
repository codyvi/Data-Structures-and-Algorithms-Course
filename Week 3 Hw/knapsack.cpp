#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef struct {
   int v;
   int w;
   double d;
} Item;

void input(Item items[],int sizeOfItems) {
   //cout << "Enter total "<< sizeOfItems <<" item's values and weight" << endl;
   for(int i = 0; i < sizeOfItems; i++) {
     //cout << "Enter "<< i+1 << " V ";
      cin >> items[i].v;
      //cout << "Enter "<< i+1 << " W";
      cin >> items[i].w;
   }
}


// void display(Item items[], int sizeOfItems)
// {
  
//    cout << "values: ";
//    for(int i = 0; i < sizeOfItems; i++) {
//       cout << items[i].v << "\t";
//    }
//    cout << endl << "weight: ";
//    for (int i = 0; i < sizeOfItems; i++) {
//       cout << items[i].w << "\t";
//    }
//    cout << endl;
// }
bool compare(Item i1, Item i2) {
   return (i1.d > i2.d);
}

double knapsack(Item items[], int sizeOfItems, int W) 
{
   Item mx, temp;
   double totalValue = 0.0, totalWeight = 0.0;
   for (int i = 0; i < sizeOfItems; i++) 
   {
      items[i].d = ((double) items[i].v / items[i].w );
   }

   sort(items, items+sizeOfItems, compare);

   for(int i=0; i<sizeOfItems; i++) 
   {
      if(totalWeight + items[i].w<= W) 
      {
         totalValue += items[i].v ;
         totalWeight += items[i].w;
      } 

      else 
      {
         double wt = W-totalWeight;
         totalValue += (wt * ( (double) items[i].d));
         totalWeight += wt;
         break;
      }
   }
   //cout << "total weight in bag " << totalWeight<<endl;
   return totalValue;
}
int main() {
   int W;
   int n;
   cin >> n;
   //cout<< "Enter Knapsack weight \n";
   cin >> W;
   Item items[n];
   input(items, n);
   //cout << "Entered data \n";
   //display(items,4);
   double mxVal = knapsack(items, n, W);
   std::cout.precision(10);
   cout << mxVal << endl;
}