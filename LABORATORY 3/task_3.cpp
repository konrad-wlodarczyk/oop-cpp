#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

using namespace std;

class IP
{
    private: 
        unsigned int m_ip;
        
    public:
        IP(const string& ip)
        {
            istringstream address(ip);
            string octet;
            
            int count = 0;
            
            while(getline(address, octet, '.'))
            {
                assert(count <= 4);
                
                int value = stoi(octet);
                
                assert(value >= 0 && value <= 255);
                
                m_ip = (m_ip << 8) | value;
                
                count++;
            }
            
            assert(count == 4);
        }
        
        friend ostream& operator<<(ostream& out, IP& ip);
        
    
};

ostream& operator<<(ostream& out, IP& ip)
{
    out << ((ip.m_ip >> 24) & 0xFF) << '.' << ((ip.m_ip >> 16) & 0xFF) << "." << ((ip.m_ip >> 8) & 0xFF) << "." << (ip.m_ip & 0xFF) << endl;
    
    return out;
    
};

int main()
{
    //CREATING A VALID ADDRESS
    IP address1("192.168.1.1");
    cout << "The stored IP address: " << address1 << endl;
    
    //CREATING AN ADDRESS WITH TOO MANY OCTETS
    //IP address2("192.168.1.1.1");
    //cout << "The stored IP address: " << address2 << endl;
    
    //CREATING AN ADDRESS WITH VALUE NOT BETWEEN 0 AND 255
    IP address3("213.168.1.1");
    cout << "The stored IP address: " << address3 << endl;

    return 0;
}