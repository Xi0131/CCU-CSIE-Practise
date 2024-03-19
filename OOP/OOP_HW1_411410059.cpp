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
        // qubit(){
        //     vec = new vector<int>;
        // }
        void swap(qubit &x);
        void add_connection(int node);
};

// swap connected node
void qubit::swap(qubit &x){
    vec.swap(x.vec);
}

void qubit::add_connection(int node){
    vec.push_back(node);
}

int main()
{
    int logQubits, gates, precedences, phyQubits, phyLinks;
    cin >> logQubits >> gates >> precedences >> phyQubits >> phyLinks;
    qubit a;
    vector<pii> gate_id = {{0, 0}};
    for(int i = 0, a, b, c; i < gates; i++){
        cin >> a >> b >> c;
        gate_id.push_back(make_pair(b, c));   
    }
    vector<int> precedence_id[gates + 1];
    int in[gates + 1];
    for(int i = 0; i < gates + 1; i++) in[i] = 0;
    for(int i = 0, a, b, c; i < precedences; i++){
        cin >> a >> b >> c;
        precedence_id[b].push_back(c);
        in[c]++;
    }
    vector<qubit> qb(phyQubits + 1);
    int slots[phyQubits + 1];
    for(int i = 0, a, b, c; i < phyLinks; i++){
        cin >> a >> b >> c;
        qb[b].add_connection(c);
        qb[c].add_connection(b);
    }
    // for(int i = 0; i < qb[1].vec.size(); i++) watch(qb[2].vec[i]);
    
    for(int i = 1; i <= logQubits; i++){
        cout << i << ' ' << i << '\n';
    }
    
	return 0;
}