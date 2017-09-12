#include <memory>
using std::shared_ptr;


#include "Test.h"

int main(int, char**) {
    using TestPtr = shared_ptr<QObject>;

    QList<TestPtr> tests = {
        TestPtr(new BoardTest(5, 5)),
    };

    for (const TestPtr& test: tests) {
        QTest::qExec(test.get(), QStringList());
    }

    return 0;
}
