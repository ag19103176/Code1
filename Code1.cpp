#include<bits/stdc++.h>
using namespace std;
void inputArray(vector<vector<int>>&arr,int row,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            arr[i][j]=rand()%100;
        }
    }
}
void sortColumn(vector<int> &arr, int min, int max)
{
    int n = arr.size();
    int ans[n];
    int RANGE = max-min+1;
    int count[RANGE + 1];
    memset(count, 0, sizeof(count));
    int i=0;
    for (i = 0; i < n; ++i)
        count[arr[i]]++;
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];
    for (i = n-1; i>=0; --i)
    {
        ans[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    for (i = 0; i<n; ++i)
        arr[i] = ans[i];
}
void sortArray(vector<vector<int>> &arr, int columnIndex) {
    vector<int> unsorted;
    for(int i=0; i<arr.size(); i++) {
      unsorted.push_back(arr[i][columnIndex]);
    }
  
    sortColumn(unsorted, 0, 100);
  
    for(int i=0; i<arr.size(); i++) {
      arr[i][columnIndex] = unsorted[i];
    }
    
}

void printArray(vector<vector<int>>arr,int row,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int row,col;
    cout<<"Enter the rows and column"<<endl;
    cin>>row>>col;
    vector<vector<int>>arr(row,vector<int>(col));
    inputArray(arr,row,col);
    printArray(arr,row,col);
    cout<<"enter the column to be sort in the range"<<endl;
    int sortCol;
    cin>>sortCol;
    sortArray(arr,sortCol-1);
    cout<<"COL after sorted"<<endl;
    printArray(arr,row,col);
    return 0;
    
}
