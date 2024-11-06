package graph;

import java.util.*;

public class BFS<T> {
    
    
    public ArrayList<T> bfs(HashMap<T, List<T>> adj, T start)
    {
        ArrayList<T> result = new ArrayList<>();
        Queue <T>  q = new LinkedList<>();
        HashMap < T, Boolean> vis = new HashMap<>();
        q.add(start);
        vis.put(start, true);
        while(!q.isEmpty()){
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                T s = q.poll();
                result.add(s);
                for(T v : adj.get(s))
                {
                    if(vis.getOrDefault(v,false) == false)
                    {
                        q.add(v);
                    }
                }
            }
        }
        return result;
    }
    public void main(String args[])
    {
        BFS<Integer> BFSObj = new BFS<>();
        HashMap< Integer, List<Integer>> sample = new HashMap<>();
        for(int i = 0; i< 10; i++)
        {
            sample.put(i, new LinkedList<>());
        }
        sample.get(0).add(1);
        sample.get(0).add(3);
        sample.get(0).add(4);
        sample.get(1).add(2);

        ArrayList<Integer> ans = BFSObj.bfs(sample, 0); 
        System.out.println(ans);

    }
    
}
