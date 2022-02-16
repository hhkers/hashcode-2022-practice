#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <random>
#include <iterator>

using namespace std;

string IN[6] = { "inputs/a_an_example.in.txt", "inputs/b_basic.in.txt", "inputs/c_coarse.in.txt", "inputs/d_difficult.in.txt", "inputs/e_elaborate.in.txt" };
string OUT[6] = { "outputs/a_an_example.in.txt", "outputs/b_basic.in.txt", "outputs/c_coarse.in.txt", "outputs/d_difficult.in.txt", "outputs/e_elaborate.in.txt" };
string OUT_OPT[6] = { "outputs/a_an_example.opt.txt", "outputs/b_basic.opt.txt", "outputs/c_coarse.opt.txt", "outputs/d_difficult.opt.txt", "outputs/e_elaborate.opt.txt" };

int C = 4;

vector<vector<string>> likes;
vector<vector<string>> dislikes;
set<string> all;
int N;

int score(set<string>& ingreds) {
    int s = 0;
    for(int i=0;i<N;i++) {
        bool fail = false;
        for(auto like: likes[i]) {
            if (ingreds.find(like) == ingreds.end()) {
            //if (find(ingreds.begin(), ingreds.end(), like) == ingreds.end()) {
                fail = true;
                break;
            }
        }
        if (!fail) {
            for(auto dislike: dislikes[i]) {
                if (ingreds.find(dislike) != ingreds.end()) {
                //if(find(ingreds.begin(), ingreds.end(), dislike) != ingreds.end()) {
                    fail = true;
                    break;
                }
            }
        }
        if (!fail)
            s++;
    }
    return s;
}

int main() {
    freopen(IN[C].c_str(), "r", stdin);

    string buf;
    cin >> N;
    likes.assign(N, vector<string>());
    dislikes.assign(N, vector<string>());
    int t;
    for(int i=0;i<N;i++) {
        cin >> t;
        for(int j=0;j<t;j++) {
            cin >> buf;
            likes[i].push_back(buf);
            all.insert(buf);
        }
        cin >> t;
        for(int j=0;j<t;j++) {
            cin >> buf;
            dislikes[i].push_back(buf);
            all.insert(buf);
        }
    }

    freopen(OUT[C].c_str(), "r", stdin);
    int Nout;
    cin >> Nout;
    set<string> ingreds;
    for(int i=0;i<Nout;i++) {
        cin >> buf;
        ingreds.insert(buf);
    }

    vector<string> allv(all.begin(), all.end());

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, N-1);
    
    int maxScore = score(ingreds);
    for(int i=0; i<200000; i++) {
        auto tmpIng = ingreds;
        int k = dis(gen);
        bool alreadyLike = true;
        for(auto ing: likes[k]) {
            if (tmpIng.find(ing) == tmpIng.end()){
                tmpIng.insert(ing);
                alreadyLike = false;
            }
        }
        for(auto ing: dislikes[k]) {
            if (tmpIng.find(ing) != tmpIng.end()){
                tmpIng.erase(ing);
                alreadyLike = false;
            }
        }
        if (alreadyLike)
            continue;

        int tmpScore = score(tmpIng);
        if (tmpScore >= maxScore) {
            maxScore = tmpScore;
            ingreds = tmpIng;
        }
        if( i%1000 == 0) {
            cout << maxScore << " " << i << endl;
        }
    }
    cout << "-----" << endl;
    cout << score(ingreds) << endl;

    freopen(OUT_OPT[C].c_str(), "w", stdout);
    cout << ingreds.size();
    for(auto k: ingreds) {
        cout << " " << k;
    }

    return 0;

}
