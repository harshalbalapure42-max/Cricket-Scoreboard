#include <iostream> 
using namespace std ; 
class Team { 
    int runs ; 
    int overs ; 
    int balls ; 
    int wickets ; 
    public : 
    string name ; 
    Team () { 
        runs = 0 ; 
        wickets = 0 ; 
        overs = 0 ; 
        balls = 0 ; 
    }
    void addRuns (int r) { 
        runs += r ; 
    }
    void addOver () { 
        overs ++ ; 
        balls = 0 ; 
    }
    void addBall () { 
        balls ++ ; 
    }
    void addWicket () { 
        wickets ++ ; 
    }
    void score () { 
        cout << endl << name << " : " << runs << "/" << wickets << "          Overs : " << overs << "." << balls ; 
    }
    void target () { 
        cout << endl << "Target : " << runs + 1 ; 
    }
    int showRuns () { 
        return runs ; 
    }
    int showWickets () { 
        return wickets ; 
    }
} ; 
void scoreBoard (Team &t, int &overs, int target, int r, int w) { 
    for (int i=1; i<=overs*6; i++) { 
        int wickets = t.showWickets () ; 
        if (wickets==10) return ; 
        int currentRuns = t.showRuns () ; 
        cout << endl << "Enter runs : " ; 
        int runs ; 
        if (target==1) { 
            if (currentRuns>r) return ; 
        }
        cin >> runs ; 
        if (runs>6) { 
            if (runs==50) { 
                cout << endl << "Runs scored on No/Wide ball : " ; 
                int r ; 
                cin >> r ; 
                t.addRuns (r+1) ; 
                i -- ; 
            }
            else if (runs==100) { 
                t.addWicket () ; 
            }
            
        }
         else t.addRuns (runs) ;
        if (runs!=50) { 
            if (i%6==0) t.addOver () ; 
            else t.addBall () ; 
        }
        t.score () ;  
    }
    if (target==0) t.target () ; 
}
int main () { 
    Team t1, t2 ; 
    cout << "First team : " ; 
    string str1, str2 ; 
    cin >> str1 ; 
    cout << endl << "Second team : " ; 
    cin >> str2 ; 
    t1.name = str1 ; 
    t2.name = str2 ; 
    cout << endl << "Total overs : " ; 
    int overs ; 
    cin >> overs ; 
    cout << endl << "Note : Use 50 for No/Wide ball and 100 for wicket " ; 
    scoreBoard (t1, overs, 0, 0, 0) ; 
    cout << endl << "Second inning : " ; 
    int r = t1.showRuns () ; 
    int w = t1.showWickets () ; 
    scoreBoard (t2, overs, 1, r, w) ; 
    int r2 = t2.showRuns () ; 
    int w2 = t2.showWickets () ; 
    if (r>r2) cout << endl << t1.name << " won by " << r-r2 << " runs" ; 
    else cout << endl << t2.name << " won by " << 10-w2 << " wickets" ; 
}