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
   Character {
      CharacterID INTEGER PRIMARY KEY
      name VARCHAR(128)
      class VARCHAR(128)
      clothes TEXT
      level INT
      dialog TEXT
   }
   Customer {
      CustomerID INTEGER PRIMARY KEY
      name TEXT
      money_left INT
      password VARCHAR(128)
      email VARCHAR(255)
      CharacterID INTEGER
      FOREIGN KEY (CharacterID) REFERENCES Character(CharacterID)
   }
   Object {
      ObjectID INTEGER PRIMARY KEY
      name VARCHAR(128)
      type TEXT
      cost INT
   }
   Product {
      ProductID INTEGER PRIMARY KEY
      name VARCHAR(128)
      cost INT
      CategoryID INTEGER
      FOREIGN KEY (CategoryID) REFERENCES Category(CategoryID)
   }
   Order {
      OrderID INTEGER PRIMARY KEY
      ClientID INTEGER
      Date DATE
      Status BOOL
      ProductID INTEGER
      FOREIGN KEY (ProductID) REFERENCES Product(ProductID)
   }
   Category {
      CategoryID INTEGER PRIMARY KEY
      name VARCHAR(128)
      description TEXT
   }

   Order ||--o{ Product : has
   Object ||--o{ Customer : has
   Character ||--o{ Customer : has
   Product ||--o{ Object : has
   Category ||--o{ Product : has

```
