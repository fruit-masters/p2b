# SPEC

## "cashew" - phonebook server

stores `username`, `ip`, `port`, `rsa_public_key`, `timestamp` for every user registered on that server.

register with unique `username` and `rsa_public_key` once.

update of `ip`, `port` and `timestamp` only possible if signed with users `rsa_private_key`.

## "p2b" - message client

### initial user creation

`rsa_private_key` and `rsa_public_key` get created and stored locally.

register the user on a cashew server.

### finding peer

both users need to be online and have their latest info on their respective cashew server.  

call up other peers cashew server with their `username` to query their newest `ip`, `port` and `rsa_public_key`.

### connecting to peer

#### establishing authentication on connection buildup

exchange `username` and `rsa_public_key` with peer and match with foreign cashew server.

both peers generate ephemeral Diffie-Hellman public key.  
they exchange ephemeral key and compute their `shared_secret`.  
they then derive a symmetric `session_key` from the `shared_secret` using SHA-256.

#### sending messages

check if connection is still valid, if not, authenticate again with peer.

all messages are encrypted with the `session_key` using AES.

### message flow

1. check if connection valid  
if, valid send message  
if invalid, go to step 2
2. attempt to reconnect to latest known `ip`:`port`  
if successful, send message  
if not, go to step 3
3. query cashew for updated `ip`:`port`  
if updated, reconnect and send message  
if no update, go to step 4
4. mark the peer as offline and store message locally  
ping peer periodically to know if online