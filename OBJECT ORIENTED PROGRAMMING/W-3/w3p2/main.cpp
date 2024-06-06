#include "Vendor.h"
using namespace seneca;
int main() {
    Vendor vendor;
    vendor.setEmpty();
    vendor.takeOrders();
    vendor.displayOrders();
    vendor.clearData();
    return 0;
}
