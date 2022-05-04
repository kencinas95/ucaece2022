#include <iostream>
#include <cstdlib>
#include <cstring>

#define MAX_AUTHORS 100
#define bzero(x, l) (std::memset(x, 0, sizeof(Author) * l))

typedef struct {
    std::string name;
    int sales;
} Author;

typedef struct {    
    int book_id;
    int amount;
    Author author;
} Sale;

static unsigned int SEQ_AUTHORS = 0;
static Author AUTHORS[MAX_AUTHORS];

int get_int_from_console();
bool has_next_sale();

void purchase(Sale&);

int insert(Author);
int find_by_name(std::string);
Author by_author_name(std::string);
void show_sales_per_author();

int main(int argc, const char **argv)
{    
    bzero(AUTHORS, MAX_AUTHORS);
    while (has_next_sale())
    {
        Sale sale;
        purchase(sale);
    }

    show_sales_per_author();

    return 0;
}

int get_int_from_console()
{
    int number;
    while (true)
    {
        std::cin >> number;
        if (std::cin.fail())
        {
            std::cout << "\nSorry, I don't understand!" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        } else {
            return number;
        }
    }
}

bool has_next_sale()
{
    unsigned int opt;

    while (true)
    {
        std::cout << "New sale?" << std::endl;
        std::cout << "1-Yes, 2-No: >";
        opt = get_int_from_console();
        switch (opt)
        {
            case 1: 
                return true;
                break;
            case 2:
                return false;
                break;
            default:
                std::cout << "\nNot a valid option!" << std::endl;                
                break;
        }
    }
}

void purchase(Sale &sale)
{
    std::system("clear");
    
    std::cout << "Book ID: ";    
    sale.book_id = get_int_from_console();

    std::cout << "\nAmount: ";
    sale.amount = get_int_from_console();

    std::string author_name;
    std::cout << "\nAuthor: ";
    std::cin >> author_name;
    
    int author_id = find_by_name(author_name);
    if (author_id < 0)
    {
        sale.author.name = author_name;
        sale.author.sales = 0;
        if ((author_id = insert(sale.author)) < 0)
        {
            std::cout << "Could not insert new author, purchase cancelled!" << std::endl;
            return;
        }
    }
    AUTHORS[author_id].sales += sale.amount;
    
    std::cout << "Finish sale!";
    std::cin.get();
    std::cin.get();
    
    std::cout << std::endl;
    std::cout << std::endl;
}

int find_by_name(std::string name)
{    
    int i = 0;  
    while (i < SEQ_AUTHORS)
    {        
        if (AUTHORS[i].name == name)
        {                        
            return i;
        } else {
            i++;            
        }
    }
    return -1;
}

int insert(Author author)
{                    
    if (SEQ_AUTHORS < MAX_AUTHORS)
    {        
        AUTHORS[SEQ_AUTHORS] = author;
        SEQ_AUTHORS++;
        std::cout << "New author inserted: ";
        std::cout << SEQ_AUTHORS;
        std::cout << " " + author.name << std::endl;
    } else {
        std::cout << "Max authors reached!" << std::endl;
        return -1;
    }    
    return SEQ_AUTHORS;
}

void show_sales_per_author()
{
    std::system("clear");

    std::cout << "Sales Ranking!" << std::endl;
    for (int i = 0; i < SEQ_AUTHORS; i++)
    {
        std::cout << "------------------" << std::endl;
        std::cout << "- Author: ";
        std::cout << AUTHORS[i].name;
        std::cout << "\n Books: ";
        std::cout << AUTHORS[i].sales << std::endl;
    }
}