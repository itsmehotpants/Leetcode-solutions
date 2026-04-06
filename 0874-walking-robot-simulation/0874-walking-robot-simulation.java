class Solution {
    public int robotSim(int[] cmd, int[][] obs) {
        HashSet<String> hset= new HashSet<>();
        for(int ob[]: obs){
            hset.add(ob[0]+"#"+ob[1]);
        }
        int x=0,y=0;
        int dir[][]={{0,1},{1,0},{0,-1},{-1,0}};
        int pos = 0;
        int ans= 0;
        for(int c:cmd){
            if(c==-1) pos = (pos+1)%4;
            else if(c==-2) pos=(pos+3)%4;
            else {
                for(int i=0;i<c;i++){
                    String key = (x+dir[pos][0])+ "#" + (y + dir[pos][1]);
                    if(hset.contains(key)) break;
                    else{
                        x= x+dir[pos][0];
                        y=y+dir[pos][1];
                    }
                }
                ans =Math.max(ans,x*x+y*y);
            }
        }
 return ans;
    }
}