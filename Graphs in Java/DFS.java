package graph;
import java.util.*;
public class DFS<T> {

    private  ArrayList<T> dfsImplementation (HashMap<T, List<T>> adj)
    {
        ArrayList<T> res = new ArrayList<>();
        HashMap<T,  Boolean> vis = new HashMap<>();
        for(T s :  adj.keySet())
        {
            dfs(adj, s, res, vis);
        }
        
        return res;
    }
    public  void dfs (HashMap<T, List<T>> adj, T node, ArrayList<T> res, HashMap<T,  Boolean> vis)
    {
        if(node == null) return;
        if(vis.getOrDefault(node, false))return;
        vis.put(node, true);
        res.add(node);
        List<T> neighbors =adj.get(node);
        if(neighbors == null)return;
        for(T v : neighbors)
        {
            if(v == null)return;
            if(vis.getOrDefault(v, false) == false)
            {
                dfs(adj, v, res, vis);
            }
        }
    }
    public static void main(String args[])
    {
        DFS<String> dfsObj = new DFS<>();
       
        HashMap<String, List<String>> adj = new HashMap<>();
       
        adj.put("hello", new LinkedList<String>());
        adj.put("jello", new LinkedList<String>());
        adj.put("bello", new LinkedList<String>());
        adj.put("yello", new LinkedList<String>());
        adj.put("mello", new LinkedList<String>());

        adj.get("hello").add("jello");
        adj.get("hello").add("mello");
        adj.get("jello").add("yello");

        ArrayList<String> ans = dfsObj.dfsImplementation(adj);
        System.out.println(ans);
        DFS<Integer> dfsObj2  = new DFS<>();
        HashMap<Integer, List<Integer>> adj2 = new HashMap<>();
        for(int i = 0; i < 5; i++)
        {
            adj2.put(i, new LinkedList<Integer>());
        }
        adj2.get(0).add(2);
        adj2.get(0).add(3);
        adj2.get(0).add(1);
        adj2.get(1).add(0);
        adj2.get(2).add(0);
        adj2.get(2).add(4);
        adj2.get(3).add(0);
        adj2.get(4).add(2);
        ArrayList<Integer> ans2 = dfsObj2.dfsImplementation(adj2);
        System.out.println(ans2);







    }
    
    
}
