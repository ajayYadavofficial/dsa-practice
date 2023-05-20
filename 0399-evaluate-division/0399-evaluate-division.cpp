// class Solution {
// public:
//     vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
//         unordered_map<string, vector<pair<string,double>>> known_divi ;
        
//         for(int i=0; i<values.size(); i++){
            
//             string numerator  = equations[i][0];
//             string denominator = equations[i][1];
//             // double val = values[i];
            
//             known_divi[numerator].push_back({denominator,values[i]});
//             known_divi[denominator].push_back({numerator,1.0/values[i]});
//             // known_divi.insert({denominator,{numerator,1.0/values[i]}});
            
//         }
        
//         // for(auto it : known_divi){
//         //     string num = it.first;
//         //     for(auto it2 : it.second){
//         //         string denom = it2.first;
//         //         double val = it2.second;
//         //         cout<<num<<" / "<<denom<<"  == "<<val<<endl;
//         //     }
//         // }
        
//         // auto it1 = known_divi.find("a");
//         // cout<<it1->first;
        
//         vector<double> ans;
//         for(int i=0; i<queries.size(); i++){
//             string nume = queries[i][0];
//             string denom= queries[i][1];
            
//             auto it1 = known_divi.find(nume);
//             auto it2 = known_divi.find(denom);
//             bool flag_direct = false;
//             if(it1 != known_divi.end()){
//                 for(auto it1d : it1->second){
//                     if(it1d.first == denom){
//                         flag_direct = true;
//                         cout<<nume<<"/"<<denom<<"  = "<<it1d.second<<endl;
//                         ans.push_back(it1d.second);
//                         break;
//                     }
//                 }
//             }
            
//             if(it1 !=known_divi.end() && it2!= known_divi.end() && !flag_direct)
//             {
//                 for(auto it1d : it1->second){
//                 string t1denom = it1d.first;
//                     for(auto it2d : it2->second){
//                         string t2denom = it2d.first;
//                         if(t1denom == t2denom){
//                             cout<<it1->first<<"/"<<it2->first<<endl;
//                             cout<<it1d.second/it2d.second<<endl;
//                             ans.push_back(it1d.second/it2d.second);
//                             got_ans = true;
//                             break;
//                         }
//                     }
//                 }
//             }else if (!flag_direct) {
//                 cout<<nume<<"/"<<denom<<" == -1.0"<<endl;
//                 ans.push_back(-1.0);
//             }
            
//         }
        
//         return ans;
//     }
// };


class Solution {
public:

    void dfs(string node, string& dest, unordered_map<string, unordered_map<string, double>>& gr, unordered_set<string>& vis, double& ans, double temp) {
        if(vis.find(node) != vis.end()) return;

        vis.insert(node);
        if(node == dest){
            ans = temp;
            return;
        }

        for(auto ne : gr[node]){
            dfs(ne.first, dest, gr, vis, ans, temp * ne.second);
        }
    }

    unordered_map<string, unordered_map<string, double>> buildGraph(const vector<vector<string>>& equations, const vector<double>& values) {
        unordered_map<string, unordered_map<string, double>> gr;

        for (int i = 0; i < equations.size(); i++) {
            string dividend = equations[i][0];
            string divisor = equations[i][1];
            double value = values[i];

            gr[dividend][divisor] = value;
            gr[divisor][dividend] = 1.0 / value;
        }

        return gr;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> gr = buildGraph(equations, values);
        vector<double> finalAns;

        for (auto query : queries) {
            string dividend = query[0];
            string divisor = query[1];

            if (gr.find(dividend) == gr.end() || gr.find(divisor) == gr.end()) {
                finalAns.push_back(-1.0);
            } else {
                unordered_set<string> vis;
                double ans = -1, temp=1.0;
                dfs(dividend, divisor, gr, vis, ans, temp);
                finalAns.push_back(ans);
            }
        }

        return finalAns;
    }
};