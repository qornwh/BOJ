#include<iostream>
using namespace std;

//노드개수
int nodeN = 0;

//리프노드개수
int count = 0;

void nodeDel(int node[], int n){
    node[n] = -2;
    for(int i=0; i <nodeN; i++){
        if(n == node[i]){
            nodeDel(node, i);
        }
    }
}

void serchNode(int node[], int n){
    bool _temp = false;
    for(int i =0; i< nodeN; i++){
        if(n == node[i]){
            _temp = true;
            serchNode(node, i);
        }
    }
    if(!_temp)
        count++;
}

int main(){
    //삭제할 노드번호
    int nodeD = -1;

    cin >> nodeN;

    //노드 배열
    int node[nodeN]; 

    for(int i=0; i <nodeN; i++){
        cin >> node[i]; 
    }

    //삭제 노드
    cin >> nodeD;
    
    node[nodeD] = -2;

    nodeDel(node, nodeD);

    for(int i=0; i <nodeN; i++){
        if(node[i] == -1){
            serchNode(node, i);
        }
    }

    cout << count;

    return 0;
}