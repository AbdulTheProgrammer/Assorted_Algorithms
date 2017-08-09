
#include <stdio.h>

/* Given a bunch of strings where some of them are anagrams, sort these strings
 as such that the anagrams are grouped together. */

//Md Tahsin Sharif's Java  implementation
public static String[] anagram(String array[]){
    
    String[] original = new String[array.length];
    
    HashMap<String, ArrayList<String>> map = new HashMap<String, ArrayList<String>>();
    
    for (int i = 0; i<array.length; i++){
        original[i] = array[i];
        char[] chars = array[i].toCharArray();
        Arrays.sort(chars);
        String sorted = new String(chars);
        array[i] = sorted;
        
        if (map.containsKey(array[i])){
            ArrayList<String> value = new ArrayList<String>();
            value = map.get(array[i]);
            value.add(original[i]);
        } else {
            ArrayList<String> val = new ArrayList<String>();
            map.put(array[i], val);
            val.add(original[i]);
        }
    }
    
    ArrayList<String> list2 = new ArrayList<String>(0);
    for (Map.Entry<String, ArrayList<String>> entry1 : map.entrySet()) {
        ArrayList<String> list = entry1.getValue();
        
        Collections.sort(list);
        list2.addAll(list);
    }
    
    String[] final_array = new String[list2.size()];
    final_array = list2.toArray(final_array);
    
    return final_array;
}

///Abdul's c++ implementation
#include <algoritm>
using namespace std;
vector<strings> create_sorted_anagram_array(string arr[]) {
    map<string, vector<string>> hash_map;
    vector<string> res;
    
    //assemble hashmap
    for( el : arr) {
        string sorted = sort(el.begin(), el.end());
        if(hash_map.find(sorted) == hash_map.end()) {
            vector<string> str_list;
            hash_map[sorted] = str_list;
        }
        hash_map[sorted].push_back(el);
    }
    
    for(it_type iterator = hash_map.begin(); iterator != hash_map.end(); iterator++) {
        sort(it->second[0], it->second[it->second.length()]);
        for (el : it->second) {
            res.push_back(el);
        }
    }
    return res;
}
