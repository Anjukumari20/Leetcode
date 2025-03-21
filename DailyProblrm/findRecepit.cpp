class Solution {
    unordered_map<string, vector<string>>graph;
    unordered_map<string, bool>memo;
    unordered_set<string>visited;

    bool isPossible(string &recipe){
        if(memo.count(recipe)){
            return memo[recipe];
        }
        if(visited.count(recipe)){
            return false;
        }
        visited.insert(recipe);
        for(auto ingredient : graph[recipe]){
            if(!memo.count(ingredient) && !graph.count(ingredient)){
                return memo[ingredient] = false;
            }
            if(!isPossible(ingredient)){
                return memo[ingredient] = false;
            }
        }
        visited.erase(recipe);
        return memo[recipe] = true;
    }
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        for(int i=0; i<recipes.size(); i++){
            graph[recipes[i]] = ingredients[i];
        }

        for(auto &supply : supplies){
            memo[supply] = true;
        }
        vector<string>ans;
        for(string recipe : recipes){
            if(isPossible(recipe)){
                ans.push_back(recipe);
            }
        }
        return ans;
    }
};