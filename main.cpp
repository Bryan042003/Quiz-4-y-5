#include <iostream>
#include <algorithm>
#include<list>
#include<math.h>
using std::sort;
using std::begin;
using std::end;
using std::list;
using std::pow;
using namespace std;

int costo(int N, int M, int x[], int y[]) {
    int costototal=0;//1
    int vertical=1;//1
    int horizontal=1;//1
    int i = 0, j = 0;//2

    do{
        (x[i] > y[j])?horizontal++:vertical++;//t8
        costototal +=(x[i] > y[j])? x[i] * vertical:y[j] * horizontal;//t10
        (x[i] > y[j])?i++:j++;//t8
    }
    while (i < M && j < N );//3

    cout<<"El costo total de la barra de chocolate es de: ";
    return costototal;//t1
   //f(n)=35
   //O(c)-constante
   //Loop invariant se encuentra en la asignacón de la varible de costo total;
   //que cada vez que haga una comparación las operaciones realizadas se guardarán
   //en esta variable y de esa manera retorna su valor obtenido.
}

void radixSort(int *arr, int n, int max) {
   int i, j, m, p = 1, index, temp, count = 0; //t7
   list<int> pocket[10]; // t1  //radix of decimal number is 10
   for(i = 0; i< max; i++) {//t4
      m = pow(10, i+1);//t3n
      p = pow(10, i);//t2n
      for(j = 0; j<n; j++) {//t4n a la 2
         temp = arr[j]%m;//t3
        index = temp/p;//t2//find index for pocket array
         pocket[index].push_back(arr[j]); //t4
      }
      count = 0;//t1
      for(j = 0; j<10; j++) {//t4n a la 2
         //delete from linked lists and store to array
         while(!pocket[j].empty()) {//t3
            arr[count] = *(pocket[j].begin());//t4
            pocket[j].erase(pocket[j].begin());//t5
            count++; //t2
         }
      }
   }
}
//f(n):31n^2+10n+8
//O(n^2)-cuadratico
//Loop invariantEl loop invariant del radixsort es que se usa el
//pocket para hacer las indexaciones y el acomodo de los elementos

int comp(int const &i, int const &j) {
    return i > j;
}
int main(){
    int n=4;
    int m=6;
    int y[]={4,1,2};
    int x[]={2,1,3,1,4};
    sort(begin(y), end(y), comp);
    for(int w=0;w<n-1;w++){
        cout<<"Valores de y: "<< y[w]<<endl;
    }
    cout<<endl;
    sort(begin(x), end(x), comp);
    for(int w=0;w<m-1;w++){
        cout<<"Valores de x: "<< x[w]<<endl;
    }
    cout<<endl;

    int a =costo(n,m-1,x,y);
    cout<<a<<endl;

    return 0;
}

