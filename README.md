E-Commerce system
Overview
Apka Dukan is a console-based marketplace application built using C++. It allows users to register either as sellers or customers. Sellers can add products, update product details, or remove products from their inventory. Customers can explore available products, add items to their shopping cart (referred to as 'kart'), and manage their purchases.

Features
Seller Functionality:
Add a new product (with an ID, name, price, and description).
Update product details, including price, name, and description.
Remove products from the marketplace.
View all added products in a tabular format.

Customer Functionality:
Explore available products and view product details.
Add products to the shopping kart.
View kart contents.
Remove products from the kart

Project Structure
main() function: Initializes the program, prompts the user to choose their role (seller or customer), and manages overall control flow.
seller(): Manages all the seller's actions, such as adding, modifying, and deleting products.
customer(): Handles the customer's actions, including viewing products, adding them to the kart, and managing kart contents.
Utility functions like space(): Help format the display for better readability.
