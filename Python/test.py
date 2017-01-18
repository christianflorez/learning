db.execute("INSERT INTO orders (id, symbol, name, shares, price, timestamp) VALUES (:id, :symbol, :name, :shares, :price, :timestamp)",
            id=session["user_id"],
            symbol=stock_info["symbol"],
            name=stock_info["name"],
            shares=shares_to_buy,
            price=stock_info["price"],
            timestamp=str(datetime.now())
            )

db.execute("INSERT INTO orders (id, symbol, name, shares, price, timestamp) VALUES (:id, :symbol, :name, :shares, :price, :timestamp)",
            id=session["user_id"],
            symbol=stock_info["symbol"],
            name=stock_info["name"],
            shares=shares_to_buy,
            price=stock_info["price"],
            timestamp=str(datetime.now())
            )

db.execute("INSERT INTO orders (id, symbol, name, shares, price, timestamp) VALUES (:id, :symbol, :name, :shares, :price, :timestamp)",
            id=session["user_id"],
            symbol=stock_info["symbol"],
            name=stock_info["name"],
            shares=-(shares_to_sell),
            price=stock_info["price"],
            timestamp=str(datetime.now())
            )

db.execute("INSERT INTO orders (id, symbol, name, shares, price, timestamp) VALUES (:id, :symbol, :name, :shares, :price, :timestamp)",
            id=session["user_id"],
            symbol=stock_info["symbol"],
            name=stock_info["name"],
            shares=-(shares_to_sell),
            price=stock_info["price"],
            timestamp=str(datetime.now())
            )

def save_order(stock, amount):
    db.execute("INSERT INTO orders (id, symbol, name, shares, price, timestamp) VALUES (:id, :symbol, :name, :shares, :price, :timestamp)",
            id=session["user_id"],
            symbol=stock["symbol"],
            name=stock["name"],
            shares=amount,
            price=stock["price"],
            timestamp=str(datetime.now())
            )

def update_portfolio(mode, stock, amount):
    if mode == "create":
        db.execute("INSERT INTO portfolio (id, symbol, name, shares, price) VALUES (:id, :symbol, :name, :shares, :price)",
                       id=session["user_id"],
                       symbol=stock["symbol"],
                       name=stock["name"],
                       shares=amount,
                       price=stock["price"]
                       )  
    elif mode == "update":
        db.execute("UPDATE portfolio SET shares = shares + :shares WHERE (id = :id AND symbol = :symbol)",
                   shares=amount,
                   id=session["user_id"],
                   symbol=stock["symbol"]
                   )  