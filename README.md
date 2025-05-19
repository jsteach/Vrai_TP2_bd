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
      CharacterID INTEGER PK
      name VARCHAR(128)
      class VARCHAR(128)
      clothes TEXT
      level INT
      dialog TEXT
   }
   Customer {
      CustomerID INTEGER PK
      name TEXT
      money_left INT
      password VARCHAR(128)
      email VARCHAR(255)
      CharacterID INTEGER
   }
   Object {
      ObjectID INTEGER PK
      name VARCHAR(128)
      type TEXT
      cost INT
   }
   Product {
      ProductID INTEGER PK
      name VARCHAR(128)
      cost INT
      CategoryID INTEGER
   }
   Order {
      OrderID INTEGER PK
      ClientID INTEGER
      Date DATE
      Status BOOL
      ProductID INTEGER
   }
   Category {
      CategoryID INTEGER PK
      name VARCHAR(128)
      description TEXT
   }

   Customer ||--o{ Character : has
   Customer ||--o{ Object : has
   Order ||--o{ Product : contains
   Product ||--o{ Category : belongs_to
   Product ||--o{ Object : has


```
