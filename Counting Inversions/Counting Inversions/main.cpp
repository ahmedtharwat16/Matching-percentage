//
//  main.cpp
//  Counting Inversions
//
//  Created by Ahmed Tharwat Wagdy on 6/30/20.
//  Copyright © 2020 Ahmed Tharwat Wagdy. All rights reserved.
//

#include <iostream>
using namespace std;
#include <math.h>       /* pow */
pair<int,int>*inversions;
int k=0;
long merge_count(int* arr,int first1 ,int last1,int last2){
    long count=0;
    int first2=last1+1;
    int i=0;
    int f=first1,l=last2;
    int* result=new int[last2-first1+1];
    while (first1<=last1&&first2<=last2) {
        if(arr[first1]<arr[first2])
            result[i++]=arr[first1++];
        else {
            
            count+=last1-first1+1;
            int temp=first1;
            while (temp<=last1)
                inversions[k++]=make_pair(arr[first2],arr[temp++]);
            result[i++]=arr[first2++];
        }
    }
        while (first1<=last1)   result[i++]=arr[first1++];
         while (first2<=last2)   result[i++]=arr[first2++];
    i=0;
    for(int j=f;j<=l;j++)    arr[j]=result[i++];
    return count;
}
long count(int* array,int start,int end){
    if(end-start==0)    return 0;
    else{
        int mid=start+((end-start)/2);
        long x= count(array, start, mid);
        long y= count(array, mid+1,end);
        long z= merge_count(array,start,mid,end);
        return x+y+z;
    }
}
int* getArray(char* filename,int n){
    int*array= (int*)malloc(sizeof(int)*n);
    int counter =0;
    int x=0;
    FILE*f;
    f=fopen(filename, "r");
    while (!feof(f)) {
        fscanf(f, "%d",&x);
        array[counter++]=x;
    }
    fclose(f);
    cout<<counter<<endl;
    return array;
}
float getMatchingPercentage(long inv,int len){
    int maxinv=len*(len-1)/2;     //order of n^2
    return 100-(((float)inv/(float)maxinv)*100);
//    return maxinv/inv*100;
}

int main(int argc, const char * argv[]) {
//    int array[6]= {1,3,5,2,4,6};  //testcase I

//    int array[6]={1,5,3,6,4,2};     //testcaseII
    inversions=
    (pair<int, int>*)malloc(sizeof(pair<int, int>)*pow(sizeof(array)/sizeof(array[0]),2));
    cout<<"Matching Percentage= "<<getMatchingPercentage(count(array, 0, 5),sizeof(array)/sizeof(array[0]))<<"%"<<endl;
    for (int i=0 ;i<k; i++) {
        cout<<i<<"   ";
        cout<<"("<<inversions[i].first<<" , "<<inversions[i].second<<")"<<endl;
    }
    return 0;
}
