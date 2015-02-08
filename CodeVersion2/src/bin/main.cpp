#include <iostream>
#include "GFA/Point3D.h"

int main(int , char **)
{
    std::cout << "Tests on gfa library" << std::endl;

    std::cout << "Create Point3D and assign to other Point3D" << std::endl;
    GFA::Point3D pa(1,2,3);
    GFA::Point3D pb(4,5,6);
    std::cout << pa.x << " " << pa.y << " " << pa.z << std::endl;
    std::cout << pb.x << " " << pb.y << " " << pb.z << std::endl;
    pa = pb;
    std::cout << pa.x << " " << pa.y << " " << pa.z << std::endl;
    GFA::Point3D pd(pb);
    std::cout << pd.x << " " << pd.y << " " << pd.z << std::endl;
    // This should give an error
    //GFA::Point3D pe(pc);
    
    return 0;
}

