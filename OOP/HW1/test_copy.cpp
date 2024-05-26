#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;

class qubit{
    public:
        vector<int> vec;
        int logQubit;
        void swap_qubit(qubit &x);
        void add_connection(int node);
};

// swap connected logqubit
void qubit::swap_qubit(qubit &x){
    swap(logQubit, x.logQubit);
}

// add connection between phyqubit
void qubit::add_connection(int node){
    vec.push_back(node);
}

int bfs(int ls, int le, int (&slots)[], vector<qubit> &qb, vector<pair<int, pair<int, int>>> &ans){
    bool qvis[100000];
    int qparent[100000];
    memset(qvis, 0, sizeof(qvis));
    memset(qparent, 0, sizeof(qparent));
    
    int sQubit = slots[ls];
    queue<int> q;
    q.push(sQubit);
    
    int qtmp = q.front();
    while(!q.empty()){
        q.pop();

        // break if found
        if(qb[qtmp].logQubit == le){
            break;
        }

        for(int x : qb[qtmp].vec){
            if(!qvis[x]){
                q.push(x);
                qparent[x] = qtmp;
                qvis[x] = true;
            }
        }
        
        qtmp = q.front();
    }

    int qbacktrack = qtmp;
    while(qparent[qbacktrack] != sQubit){
        ans.push_back(make_pair(1, make_pair(qb[qbacktrack].logQubit, qb[qparent[qbacktrack]].logQubit)));
        swap(slots[qb[qbacktrack].logQubit], slots[qb[qparent[qbacktrack]].logQubit]);
        swap(qb[qbacktrack].logQubit, qb[qparent[qbacktrack]].logQubit);
        qbacktrack = qparent[qbacktrack];
    }
    return 0;
}

bool cmp(pii a, pii b){
    if(a.second > b.second) return true;
    else return false;
}

int main()
{
    int n;
    int arr[10];
    cin >> n;
    if(n) watch(arr[10000]);
    
	return 0;
}