#include "store.h"
#include <assert.h>
void ui_store(GameData* g){
      void database_init_tables(GameData* g);
}
void show_character(GameData* g){
    Classe* class;
    Character* c;
}
void select_item(GameData* g){
    Items* it;
}
void buy_item(GameData* g){
    Wallet* w;
    Client* client;
}
char* insert_object_table = ""; //TODO implementer commande insertion

void sort_elements(GameData* g){
     if (sqlite3_exec(g->db, insert_object_table,  NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    sort_table(g);
}
void apply_view(GameData* g){
    if (sqlite3_exec(g->db, view_to_apply,  NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    character_view(g);
}