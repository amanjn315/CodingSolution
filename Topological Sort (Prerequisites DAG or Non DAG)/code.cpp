class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > g(numCourses,vector<int> ());
        for(int i=0;i<prerequisites.size();i++){
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];
            g[y].push_back(x);
        }
        vector<int> ts;
        if(isCyclic(numCourses,g))
            return ts;
        stack<int> Stack; 
        vector<bool> visited(numCourses,false);
        for (int i = 0; i < numCourses; i++) 
            if (visited[i] == false) 
                topologicalSortUtil(g,i, visited, Stack); 

        // Print contents of stack 
        while (Stack.empty() == false) { 
            ts.push_back(Stack.top()); 
            Stack.pop(); 
        } 
        return ts;
    }
    bool isCyclic(int V,vector<vector<int> >& g){
        vector<bool> visited(V,false);
        vector<bool> recStack(V,false);

        // Call the recursive helper function to detect cycle in different 
        // DFS trees 
        for(int i = 0; i < V; i++) 
            if (isCyclicUtil(g,i, visited, recStack)) 
                return true; 
        return false; 
    }
    bool isCyclicUtil(vector<vector<int> >& g,int v,vector<bool>& visited, vector<bool>& recStack) 
    { 
        if(visited[v] == false) 
        { 
            // Mark the current node as visited and part of recursion stack 
            visited[v] = true; 
            recStack[v] = true; 

            for(int i = 0; i <g[v].size(); ++i) 
            { 
                if ( !visited[g[v][i]] && isCyclicUtil(g,g[v][i],visited, recStack) ) 
                    return true; 
                else if (recStack[g[v][i]]) 
                    return true; 
            } 

        } 
        recStack[v] = false;  // remove the vertex from recursion stack 
        return false; 
    } 
    void topologicalSortUtil(vector<vector<int> >& g,int v,vector<bool>& visited,stack<int>& Stack) 
    { 
        // Mark the current node as visited. 
        visited[v] = true; 

        for (int i = 0; i < g[v].size(); ++i) 
            if (!visited[g[v][i]]) 
                topologicalSortUtil(g,g[v][i], visited, Stack); 

        // Push current vertex to stack which stores result 
        Stack.push(v); 
    } 
};