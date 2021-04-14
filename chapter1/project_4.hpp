/* Given the truth values of the propositions p and q in
 * fuzzy logic, find the truth value of the disjunction and
 * the conjunction of p and q (see Exercises 50 and 51 of
 * Section 1.1).
 */


#ifndef PROJECT_1_4_DISCRETE
#define PROJECT_1_4_DISCRETE

class Project_1_4{
public:
    Project_1_4() = delete;
    Project_1_4(double a, double b):x(a),y(b){}
    void print();

private:
    double conjunction() {  return x>y?y:x; }
    double disjunction() {  return x<y?y:x; }
    double x;
    double y;
};

void
Project_1_4::print(){
    printf("Conjunction of %lf and %lf is %lf.\n",x,y,conjunction());
    printf("Disjunction of %lf and %lf is %lf.\n",x,y,disjunction());
    return;
}

#endif