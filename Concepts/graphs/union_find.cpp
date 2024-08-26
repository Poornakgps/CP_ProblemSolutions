#include<bits/stdc++.h>

using namespace std;

// bugs

int rank_child[100100], parent[100100], child_strength[100100], team[100100];

int no_of_childrens, queries;

int get_parent(int child){

    if(parent[child] == child) return child;

    parent[child] = get_parent(parent[child]);
}

void merge(int A, int B){

    A = get_parent(A);
    B = get_parent(B);

    if(A == B)
        return;

    if(rank_child[A] > rank_child[B]) swap(A, B);

    rank_child[B] = rank_child[B] + rank_child[A];
    child_strength[B] = child_strength[A] + child_strength[B];
    parent[A] = B; 
    team[A] = team[B];
}

void move_A_to_teamB(int A, int team_A, int team_B){

    int parent_A = get_parent(team_A);
    int parent_B = get_parent(team_B);
    rank_child[parent_A]--;
    rank_child[parent_B]++;
    child_strength[parent_A] -= A;
    child_strength[parent_B] += A;
    team[A] = team_B;
}

void solve(){

    cin >> no_of_childrens >> queries;

    for(int i = 1; i <= no_of_childrens; i++){
        child_strength[i] = i;
        parent[i] = i;
        rank_child[i] = 1;
        team[i] = i;
    }
    while(queries--){

        int operation;
        cin >> operation;
        if(operation == 1){
            int A, B;
            cin >> A >> B;
            int team_A = team[A];
            int team_B = team[B];
            merge(team_A, team_B);
        }
        else if(operation == 2){
            int A;
            cin >> A;
            int team_A = team[A];
            team_A = get_parent(team_A);
            cout<<rank_child[team_A]<<" "<<child_strength[team_A]<<endl;
        }
        else{
            int A, B;
            cin >> A >> B;
            move_A_to_teamB(A, team[A], team[B]);
        }
    }
}

int main(){

    int test_cases;
    cin >> test_cases;

    while( test_cases-- ){
        solve();
    }
}