#include "store.h"
#include <assert.h>
#include "knob.h"

#define LOG_SQLITE3_ERROR(db) knob_log(KNOB_ERROR, "%s:%d: SQLITE3 ERROR: %s\n", __FILE__, __LINE__, sqlite3_errmsg(db))
void ui_store(GameData* g){
      void database_init_tables(GameData* g);
}

const char* insert_object_table = 
"INSERT INTO Object (type, cost)"
"VALUES (Weapon, 50),"
"(Potion, 40),"
"(Armor, 80),"
"(Shield, 35),"; 

void select_item(GameData* g){
    Items* it;
    int position;
    bool is_bought;
    if(!is_bought){
        if(it != NULL){
            printf("%c", insert_object_table);
        }
    }
}
void buy_item(GameData* g){
    Wallet* w;
    Inventory* inv;
    bool is_bought;
    if(is_bought){
        if(inv->count <= inv->capacity){
            inv->count++;
            inv->capacity--;
            w->count--;
            w->ggbucks_amount--;
        }
        else{
            is_bought = false;
        }
    }
}

const char* table_to_sort = 
 "   SELECT cost, type,"
 "   FROM Object,"
 "   ORDER BY cost";

 const char* view_to_apply =
 "  CREATE VIEW ViewCharacher AS"
 "  SELECT class"
 "  FROM Character";

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
void sort_elements(GameData* g){
     if (sqlite3_exec(g->db, insert_object_table,  NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    sort_table(g);
}

const char* view_data_to_apply = "INSERT INTO Character(class, clothes, item)"
"VALUES"
"(Nord),"
"(Dark_Elf, white, armor),"
"(Dark_Elf, yellow, weapon),"
"(Redguard, red, weapon),"
"(Orc, green, armor),"
"(Orc, blue, armor),";

void apply_view(GameData* g){
    if (sqlite3_exec(g->db, view_to_apply, * view_data_to_apply,  NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    character_view(g);
}