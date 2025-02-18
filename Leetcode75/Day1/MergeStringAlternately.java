class Solution {
    public String mergeAlternately(String word1, String word2) {
        int n1=word1.length();
        int n2=word2.length();
        int min=Math.min(n1,n2);
        String longstr = "";
        
        if(min==n1)
        {
            longstr=word2;
        }
        if(min==n2)
        {
            longstr=word1;
        }
        char chars1[]=word1.toCharArray();
        char chars2[]=word2.toCharArray();
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<min;i++){
            sb.append(chars1[i]);
            sb.append(chars2[i]);
        }
        sb.append(longstr.substring(min));
        return sb.toString();

    }
    
}
