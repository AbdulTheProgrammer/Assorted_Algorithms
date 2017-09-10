
ArrayList<ArrayList<int>> subsets = new ArrayList<ArrayList<int>>();
ArrayList<ArrayList<int>> getPowerSet(ArrayList<int> set, int index) {
    if(set.size() == index) {
        //add an empty set base case
        ArrayList<int> emptySet = new ArrayList<int>();
        ArrayList<ArrayList<int>> subsets = new ArrayList<ArrayList<int>>();
        subets.put(emptySet);
        return subets;
    }
    else {
        //continuouslt divide the problem for each element in the set
        subsets = getPowerSet(set, index + 1);
        int el = set.get(index);
        ArrayList<ArrayList<int>> subsetsCopy = new ArrayList<ArrayList<int>>();
        subsetsCopy.addAll(subsets)
        //add element in each set
        for (subset : subsets) {
            ArrayList<int> newSubset = new ArrayList<int>();
            newSubset.addAll(subset);
            newSubset.add(el);
            subsetsCopy.add(newSubset);
        }
        return subsetsCopy;
    }
}