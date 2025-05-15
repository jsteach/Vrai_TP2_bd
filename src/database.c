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

void database_end(GameData* g){
    sqlite3_close(g->db);
}

const char* create_character_table = 
"CREATE TABLE IF NOT EXISTS Character("
"   CharacterID INTEGER PRIMARY KEY"
"   name VARCHAR[128]"
"   class TEXT"
"   level INT"
"   dialog TEXT"
"   class VARCHAR[128]"
")";
const char* create_customer_table = 
"CREATE TABLE IF NOT EXISTS Customer("
"   CustomerID INTEGER PRIMARY KEY"
"   name TEXT"
"   money_left INT" 
"   password VARCHAR[128]"
"   email VARCHAR[255]"
"   FOREIGN KEY (CharacterID) REFERENCES Character(CharacterID)"
"   FOREIGN KEY (ObjectID) REFERENCES Object(ObjectID)"
")";
const char* create_object_table = 
"CREATE TABLE IF NOT EXISTS Object("
"   ObjectID INTEGER PRIMARY KEY"
"   name VARCHAR[128]"
"   type TEXT"
"   cost INT"
")";
const char* create_order_table = 
"CREATE TABLE IF NOT EXISTS Order("
"   OrderID INTEGER PRIMARY KEY"
"   Client INT"
"   Date DATE"
"   Status BOOL"
"   FOREIGN KEY (ProductID) REFERENCES Product(ProductID)"
")";
const char* create_category_table = 
"CREATE TABLE IF NOT EXISTS Category("
"   CategoryID INTEGER PRIMARY KEY"
"   name VARCHAR[128]"
"   description TEXT"
")";
const char* create_product_table = 
"CREATE TABLE IF NOT EXISTS Produit("
"   ProductID INTEGER PRIMARY KEY"
"   name VARCHAR[128]"
"   cost INT"
"   FOREIGN KEY (CategoryID) REFERENCES Category(CategoryID)"
")";

 const char* table_to_sort = 
 "   SELECT cost, type"
 "   FROM Object"
 "   ORDER BY cost";

 const char* view_to_apply = 
 "  CREATE VIEW ViewCharacher AS"
 "  SELECT class"
 "  FROM Character";

void database_init_tables(GameData* g){
    if (sqlite3_exec(g->db, create_character_table,  NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
     if (sqlite3_exec(g->db, create_customer_table,  NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
     if (sqlite3_exec(g->db, create_object_table,  NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
     if (sqlite3_exec(g->db, create_order_table,  NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
     if (sqlite3_exec(g->db, create_category_table,  NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
     if (sqlite3_exec(g->db, create_product_table,  NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
}
void sort_table(GameData* g){
    if (sqlite3_exec(g->db, table_to_sort,  NULL, NULL, NULL) != SQLITE_OK) {
       LOG_SQLITE3_ERROR(g->db);
       return;
    }
}
void character_view(GameData* g){
     if (sqlite3_exec(g->db, view_to_apply,  NULL, NULL, NULL) != SQLITE_OK) {
       LOG_SQLITE3_ERROR(g->db);
       return;
    }
}
// lien pour diagramme ER mermaid si dessous
//https://mermaid.live/edit#pako:eNqNklFvgjAQx79Kc89qEFjRvi1KFrNsM8aHuZCYjlZggdbUkujU774KrboHjX26P3f343_X7iGVjAMBrsYFzRStEjGqN1pWXO0TgcxxcjJGk_d5_BLP0HQ2eXueLdBrvGhrBK04msef81ZWUvDdsuQrfWpJxNFAc6poqi31rG5D_yFZQUuZWWloH98_PNUNqg0f5KRyc7E0VZLVloKsuDPkFejkQDG3oSa80xhv11Jpqgsploxq3howiTGnrCwEvyzJZDOpdi3XqYc9IWcGHQ7drty7oRBBOd3YfLMuV-Du9rrifDf3ihzZlljqNcWav2ElEdCBTBUMiFY174DhV_QkoRk-AZ3ziidATMj4italTsBMadrWVHxJWblOJessB7Ki5caoen1asX3L56-KC7OWkayFBtIPAtxQgOxhCyTwvJ4f-Ljv-5E3GIYd2AHBuBf5oY-HUd8bhFEQHjvw2_zV60XD4AljHOGBZ5qi8PgHbeoLjA