package graph;

import java.util.*;

public class Implementation {
    
    class Graph<T>{
        private HashMap< T, List<T>> map = new HashMap<>();

        public void addVertex(T s)
        {
            map.put(s, new LinkedList<T>());
        }
        public void addEdge(T s, T d, boolean bidirectional)
        {
            if(!map.containsKey(s))
            {
                addVertex(s);
            }
            if(!map.containsKey(d))
            {
                addVertex(d);
            }
            map.get(s).add(d);
            if(bidirectional == true)
            {
                map.get(d).add(s);
            }
        }
        public int getVertexCount()
        {
            return map.keySet().size();
        }
        public int getEdgeCount(boolean bidirection)
        {
            int count  = 0;
            for(T v : map.keySet())
            {
                count += map.get(v).size();
            }
            if(bidirection == true)count = count/2;
            return count;
        }

        public boolean hasVertex(T s)
        {
            return map.containsKey(s);
        }
        public boolean hasEdge(T s, T d)
        {
            return map.get(s).contains(d);
        }
        public List<T> neighbours(T s)
        {
            System.out.println(map.get(s));
            return map.get(s);
        }
        public String toString()
        {
            StringBuilder s = new StringBuilder();
            for(T v : map.keySet())
            {
                s.append(v.toString() + ": ");
                for(T w : map.get(v))
                {
                    s.append(w.toString()+ ", ");
                }
                s.append("\n");
            }
            return s.toString();
        }

    }
    public static void main(String args[])
    {
        Graph<Integer> g =  new Implementation().new Graph<>();
        g.addVertex(2);
        g.addVertex(3);
        g.addEdge(1, 2, true);
        System.out.println(g.getEdgeCount(true));
        System.out.println(g.getVertexCount());
        System.out.println(g.hasEdge(2, 3));
        System.out.println(g.hasVertex(1));
        g.neighbours(1);
        System.out.println(g.toString());

    }
    
}
