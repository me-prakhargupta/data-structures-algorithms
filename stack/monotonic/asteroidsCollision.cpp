#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/*
    Problem: Asteroid Collision

    +ve  → moving right
    -ve  → moving left

    Collision happens only when:
    stack top > 0 AND current asteroid < 0

    Goal:
    Simulate collisions and return final surviving asteroids
*/

vector<int> astroidsCollision(vector<int>& asteroids) {
    stack<int> st; // stores surviving asteroids

    for(int asteroid : asteroids) {

        // Case 1: Moving right → no immediate collision
        if(asteroid > 0) {
            st.push(asteroid);
        } 
        else {
            /*
                Case 2: Moving left
                Possible collision with right-moving asteroids in stack
            */

            // Remove all smaller right-moving asteroids
            while(!st.empty() && st.top() > 0 && st.top() < abs(asteroid)) {
                st.pop();
            }

            /*
                Now 3 possible cases:
            */

            // Case A: Equal size → both explode
            if(!st.empty() && st.top() == abs(asteroid)) {
                st.pop();
            }
            // Case B: Stack empty OR top is left-moving → no collision
            else if(st.empty() || st.top() < 0) {
                st.push(asteroid);
            }
            // Case C: Stack top is bigger → current asteroid destroyed
            // (do nothing)
        }
    }

    /*
        Stack contains final state but in reverse order
        Convert it to vector
    */
    vector<int> res(st.size());

    for(int i = st.size() - 1; i >= 0; i--) {
        res[i] = st.top();
        st.pop();
    }

    return res;
}

int main() {
    vector<int> asteroids = {5,10,-5};

    vector<int> ans = astroidsCollision(asteroids);

    // Print result
    for(int x : ans) cout << x << " ";

    return 0;
}