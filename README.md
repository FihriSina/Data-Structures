# Data Structures - Lab Assignments

This repository contains laboratory assignments from the **Data Structures** course.  
Each C file demonstrates the implementation of a specific data structure or algorithm.  
The aim is to strengthen problem-solving skills and understanding of core data structure concepts.

## Contents

1. **DataStr1.c** – [Word Search]  
   - Searches for a given word in a **15x15 matrix** in horizontal, vertical, and diagonal directions.  
   - If found, only the letters of the word are shown; other cells are masked with `*`.

2. **DataStr2.c** – [Connected Components Counting]  
   - Uses **DFS** to find all 8-connected clusters marked with `*`.  
   - Prints the number of clusters and the size of each cluster in ascending order.

3. **DataStr3.c** – [Doubly Linked List Song Playlist]  
   - Takes a list of song names and allows **forward or backward jumps** by a given step count to display songs in a specific order.

4. **DataStr4.c** – [HTML Tag Validator]  
   - Validates whether HTML tags are properly opened and closed using a **stack**.  
   - Prints `correct` if valid, or `error <tag>` if an issue is found.

5. **DataStr5.c** – [Call List Prioritization]  
   - Sorts incoming calls based on a predefined priority order:  
     **Family > Relatives > Work/School > Friends > Bank/Cargo > Advertisement > Unknown**  
   - If priorities match, sorts alphabetically.

6. **DataStr6.c** – [Binary Search Tree (BST) for Student Grades]  
   - Inserts student IDs and grades into a BST.  
   - Performs **inorder traversal** to display sorted results and prints nodes level by level with parent information.

7. **DataStr7.c** – [AVL Tree]  
   - Inserts values into a balanced AVL tree.  
   - Displays **inorder traversal** and prints nodes level by level with parent and balance factor information.

8. **DataStr8.c** – [Red-Black Tree]  
   - Inserts values into a Red-Black tree.  
   - Displays **inorder traversal** and prints nodes level by level with parent information.

---

## Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/username/DataStructuresLabs.git
   cd DataStructuresLabs
   ````

2. Compile any lab file:

   ```bash
   gcc DataStr1.c -o lab1
   ./lab1 < input.txt
   ```

3. Provide inputs through the terminal or an input file.

---

## Requirements

* GCC or a compatible C compiler
* Basic C programming knowledge
* Command-line environment

---

## License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.

---

# Veri Yapıları - Lab Çalışmaları

Bu depo, **Veri Yapıları** dersi kapsamında yapılan laboratuvar çalışmalarını içermektedir.  
Her C dosyası, belirli bir veri yapısı veya algoritmanın uygulamasını göstermektedir.  
Amaç, problem çözme becerilerini ve temel veri yapısı kavramlarını pekiştirmektir.

## İçindekiler

1. **DataStr1.c** – [Kelime Arama]  
   - **15x15 matris** içinde verilen kelimeyi yatay, dikey ve çapraz yönlerde arar.  
   - Kelime bulunursa yalnızca kelimenin harfleri gösterilir, diğer hücreler `*` ile maskelenir.

2. **DataStr2.c** – [Bağlantılı Bileşen Sayma]  
   - `*` ile işaretlenmiş 8 yönlü bağlı kümeleri **DFS** kullanarak bulur.  
   - Küme sayısını ve her kümenin boyutunu küçükten büyüğe doğru ekrana yazar.

3. **DataStr3.c** – [Çift Yönlü Bağlı Liste ile Şarkı Listesi]  
   - Kullanıcıdan şarkı isimlerini alır ve verilen adım sayısına göre **ileri veya geri atlama** yaparak şarkıları listeler.

4. **DataStr4.c** – [HTML Etiketi Doğrulayıcı]  
   - HTML etiketlerinin doğru şekilde açılıp kapatıldığını **stack** kullanarak kontrol eder.  
   - Etiketler doğruysa `correct`, yanlışsa `error <tag>` çıktısı verir.

5. **DataStr5.c** – [Çağrı Listesi Önceliklendirme]  
   - Gelen aramaları belirli bir öncelik sırasına göre sıralar:  
     **Aile > Akraba > İş/Okul > Arkadaş > Banka/Kargo > Reklam > Bilinmeyen**  
   - Öncelikler eşitse alfabetik sıralama yapar.

6. **DataStr6.c** – [Binary Search Tree (BST) ile Öğrenci Notları]  
   - Öğrenci ID ve notlarını BST’ye ekler.  
   - **Inorder traversal** ile sıralı çıktıyı ve seviyelere göre düğüm-parent bilgilerini ekrana yazar.

7. **DataStr7.c** – [AVL Ağacı]  
   - Dengeli AVL ağacına veri ekler.  
   - **Inorder traversal** çıktısı ve seviyelere göre düğüm-parent-dengelenme bilgilerini yazdırır.

8. **DataStr8.c** – [Red-Black Tree]  
   - Red-Black ağacına veri ekler.  
   - **Inorder traversal** çıktısı ve seviyelere göre düğüm-parent bilgilerini ekrana yazar.

---

## Kullanım

1. Depoyu klonlayın:
   ```bash
   git clone https://github.com/kullanici/DataStructuresLabs.git
   cd DataStructuresLabs
   ````

2. İstediğiniz lab dosyasını derleyin:

   ```bash
   gcc DataStr1.c -o lab1
   ./lab1 < input.txt
   ```

3. Gerekli girdileri terminalden veya dosyadan sağlayın.

---

## Gereksinimler

* GCC veya uyumlu bir C derleyici
* Temel C programlama bilgisi
* Komut satırı ortamı

---

## Lisans

Bu proje **MIT Lisansı** ile lisanslanmıştır. Detaylar için [LICENSE](LICENSE) dosyasına bakabilirsiniz.

