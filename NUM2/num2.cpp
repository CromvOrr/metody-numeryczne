#include <iostream>
#include <iomanip>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{

     Eigen::MatrixXd A1(5, 5), A2(5, 5);
     Eigen::VectorXd b(5), db(5), y1(5), y2(5), dy1(5), dy2(5);

     A1 << 2.554219275, 0.871733993, 0.052575899, 0.240740262, 0.316022841,
         0.871733993, 0.553460938, -0.070921727, 0.255463951, 0.707334556,
         0.052575899, -0.070921727, 3.409888776, 0.293510439, 0.847758171,
         0.240740262, 0.255463951, 0.293510439, 1.108336850, -0.206925123,
         0.316022841, 0.707334556, 0.847758171, -0.206925123, 2.374094162;

     A2 << 2.645152285, 0.544589368, 0.009976745, 0.327869824, 0.424193304,
         0.544589368, 1.730410927, 0.082334875, -0.057997220, 0.318175706,
         0.009976745, 0.082334875, 3.429845092, 0.252693077, 0.797083832,
         0.327869824, -0.057997220, 0.252693077, 1.191822050, -0.103279098,
         0.424193304, 0.318175706, 0.797083832, -0.103279098, 2.502769647;

     b << -0.642912346, -1.408195475, 4.595622394, -5.073473196, 2.178020609;

     y1 = A1.fullPivLu().solve(b);
     y2 = A2.fullPivLu().solve(b);

     db = 1e-5 * Eigen::VectorXd::Random(5);

     dy1 = A1.fullPivLu().solve(b + db);
     dy2 = A2.fullPivLu().solve(b + db);

     cout << setprecision(13);
     cout << "\n\ny dla A1 * y  =  b:\n"
          << y1;
     cout << setprecision(16);
     cout << "\n\ny dla A1 * y  =  b + \u0394b:\n"
          << dy1;
     cout << "\n\ny dla A2 * y  =  b:\n"
          << y2;
     cout << "\n\ny dla A2 * y  =  b + \u0394b:\n"
          << dy2;
     cout << "\n\n\u0394b dla tego testu wynosiło:\n"
          << db;
     cout << "\n\n";

     return 0;
}