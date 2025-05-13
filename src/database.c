#include "database.h"
#include "sqlite3.h"

#include "knob.h"

#define LOG_SQLITE3_ERROR(db) knob_log(KNOB_ERROR, "%s:%d: SQLITE3 ERROR: %s\n", __FILE__, __LINE__, sqlite3_errmsg(db))

void database_start(GameData* g){
        sqlite3_open("game.db", &g->db);
        // sqlite3_exec((g->db, "BEGIN", NULL, NULL, NULL) != SQLITE_OK){
        // LOG_SQLITE3_ERROR(db);
        // return;
        // }
    }
    void database_init_tables(GameData* g){
    }
    void database_end(GameData* g){
        sqlite_close(g->db);
    }

const char* create_customer_table = 
"CREATE TABLE IF NOT EXISTS Customer("
"   CustomerID INTEGER PRIMARY KEY"
"   name TEXT"
"   money_left INT"
"   password VARCHAR[128]"
"   email VARCHAR[255]"
")";
const char* create_character_table = 
"CREATE TABLE IF NOT EXISTS Customer("
"   CharacterID INTEGER PRIMARY KEY"
"   name TEXT"
"   dialog TEXT"
")";
const char* create_object_table = 
"CREATE TABLE IF NOT EXISTS Customer("
"   ObjectID INTEGER PRIMARY KEY"
"   name TEXT"
"   cost INT"
")";
const char* create_product_table = 
"CREATE TABLE IF NOT EXISTS Customer("
"   ProductID INTEGER PRIMARY KEY"
"   name TEXT"
"   FOREIGN KEY (ObjectID) REFERENCES Object(ObjectID)"
")";
const char* create_order_table = 
"CREATE TABLE IF NOT EXISTS Customer("
"   OrderID INTEGER PRIMARY KEY"
"   Exportation_date INT"
"   Deadline INT"
")";
const char* create_category_table = 
"CREATE TABLE IF NOT EXISTS Customer("
"   CategoryID INTEGER PRIMARY KEY"
"   name TEXT"
"   FOREIGN KEY (ProductID) REFERENCES Product(ProductID)"
")";
