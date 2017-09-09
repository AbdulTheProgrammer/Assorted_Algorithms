/* Triple Step Pure Recursion O(3^n) */
int TripleStep(int n) {
    if(n == 0) return 1;
    if(n < 0) return 0;
    return TripleStep(n -1) + TripleStep(n - 2) + TripleStep(n - 3);
}

/* Triple Step with Memoization O(n) */
int TripleStepMemo(int n, int memo[]) {
    if(n == 0) return 1;
    if(n < 0) return 0;
    /* need to intialize to -1 as we are caching everything in range 0-n */
    if(memo[n] > -1)
        return memo[n];
    memo[n] = TripleStepMemo(n -1, memo) + TripleStepMemo(n - 2, memo) + TripleStepMemo(n - 3, memo);
    return memo[n];
}
//return value will likely overflow

/* Robot in a Grid */
// return a vector of coordinates
// input a matrix
struct Coordinate {
    int r;
    int c;
    //TODO: need to implement comparison and equality operators to use as a key in a hash map
};

/* some pretty disgusting code over here which needs some refactoring (practice), may just start using Java -sigh- */
void findPath(std::vector<Coordinate> path, bool matrix[][]), int rl, int cl) {
    std::hash_map<Coordinate, bool> memo;
    Coordinate end;
    end.r = rl -1;
    end.c = cl - 1;
    findPathHelper(path, matrix, rl, cl, end, memo);
}

bool findPathHelper(std::vector<Coordinate> path, bool matrix[][], int rl, int cl, Coordinate curr, std::hash_map<Coordinate, bool> memo) {
    if(curr.r >= rl || curr.c >= cl || curr.r < 0 || curr.c < 0 || !matrix[curr.r][curr.c])
        return false;
    if(curr.r == 0 && curr.c == 0)
        path.push_back(curr);
        return true;
    if(memo.find(curr) != end()) {
        return memo[curr];
    }
    Coordinate *upC = new Coordinate();
    upC->r = curr.r - 1;
    upC->c = curr.c;
    bool up = findPathHelper(path, matrix, rl,cl ,upC , memo);
    memo[*upC] = up;
    Coordinate *rightC = new Coordinate();
    rightC->r = curr.r;
    rightC->c = curr.c - 1;
    bool right = findPathHelper(path, matrix, rl,cl ,rightC , memo);
    memo[*rightC] = up;
    if(up || right) {
        path.push_back(curr);
        return true;
    }
    return false;
}

