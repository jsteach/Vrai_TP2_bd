###  Basic database project

Pour cloner le project:
`git clone --recursive https://github.com/chemin.vers.repos.git`

Si jamais vous ne voyez pas zig.exe dans Tools, FoundryTools_windowsx64, faite:
`.\setup.bat`

Pour compiler le project:
`ctrl+shift+b`

Pour debugger le project:
`F5`

```mermaid
erDiagram
   Character{
   CharacterID INTEGER PRIMARY KEY
   name VARCHAR[128],
   class TEXT,
   clothes TEXT,
   level INT,
   dialog TEXT,
   class VARCHAR[128],
   }
   Customer{
   CustomerID INTEGER PRIMARY KEY,
   name TEXT,
   money_left INT,
   password VARCHAR[128],
   email VARCHAR[255],"
   FOREIGN KEY (CharacterID) REFERENCES Character(CharacterID),
   FOREIGN KEY (ObjectID) REFERENCES Object(ObjectID)
   }
   Object{
      ObjectID INTEGER PRIMARY KEY
      name VARCHAR[128],
      type TEXT,
      cost INT,
   }
   Product{
      CREATE TABLE IF NOT EXISTS Produit 
      ProductID INTEGER PRIMARY KEY, 
      name VARCHAR[128], 
      cost INT, 
      FOREIGN KEY (CategoryID) REFERENCES Category(CategoryID) 
   }
   Order{
      CREATE TABLE IF NOT EXISTS Order 
      OrderID INTEGER PRIMARY KEY,  
      Client INT, 
      Date DATE,  
      Status BOOL,   
      FOREIGN KEY (ProductID) REFERENCES Product(ProductID) 
   }
   Category{
      CREATE TABLE IF NOT EXISTS Category 
      CategoryID INTEGER PRIMARY KEY,  
      name VARCHAR[128],  
      description TEXT  
   }
    Order ||--o{ Product : has
    Object ||--o{ Customer : has
    Character ||--o{ Customer : has
    Product ||--o{ Object : has
    Category ||--o{ Product : has

```