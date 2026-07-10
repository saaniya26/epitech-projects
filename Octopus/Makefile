VAULT_PASS_FILE = .vault_pass
VAULT_FILE = group_vars/vault.yml
INVENTORY_FILE = inventory
PLAYBOOK_FILE = playbook.yml
CONFIG_FILE = ansible.cfg

all:
	@echo "Available targets:"
	@echo "  make vault          - Create vault password file"
	@echo "  make encrypt        - Encrypt a password for vault_db_password"
	@echo "  make deploy         - Deploy the Ansible playbook using the vault"
	@echo "  make clean          - Remove the vault password file"

vault:
	@if [ -f $(VAULT_PASS_FILE) ]; then \
		echo "Vault password file already exists at $(VAULT_PASS_FILE)"; \
	else \
		echo "Creating vault password file..."; \
		python3 -c "import secrets; print(secrets.token_urlsafe(32))" > $(VAULT_PASS_FILE); \
		chmod 600 $(VAULT_PASS_FILE); \
		echo "✓ Vault password file created at $(VAULT_PASS_FILE)"; \
		echo ""; \
		echo "Next step: encrypt your database password"; \
		echo "  make encrypt"; \
	fi

encrypt:
	@if [ ! -f $(VAULT_PASS_FILE) ]; then \
		echo "Error: Vault password file not found at $(VAULT_PASS_FILE)"; \
		echo "Run 'make vault' first"; \
		exit 1; \
	fi
	rm -f $(VAULT_FILE)
	@read -s -p "Enter the postgres database password to encrypt: " POSTGRES_PASSWORD && echo "" && \
		read -s -p "Enter the redis password to encrypt: " REDIS_PASSWORD && echo "" && \
		read -s -p "Enter the sudo password to encrypt: " SUDO_PASSWORD && echo "" && \
		echo "Encrypting password..." && \
		ansible-vault encrypt_string --vault-password-file $(VAULT_PASS_FILE) --encrypt-vault-id default --name 'vault_db_password' "$$POSTGRES_PASSWORD" >> $(VAULT_FILE) && \
		ansible-vault encrypt_string --vault-password-file $(VAULT_PASS_FILE) --encrypt-vault-id default --name 'vault_redis_password' "$$REDIS_PASSWORD" >> $(VAULT_FILE) && \
		ansible-vault encrypt_string --vault-password-file $(VAULT_PASS_FILE) --encrypt-vault-id default --name 'vault_become_password' "$$SUDO_PASSWORD" >> $(VAULT_FILE) && \
		echo ""
	echo "✓ '$(VAULT_FILE)' updated with encrypted passwords"

deploy:
	@if [ ! -f $(VAULT_PASS_FILE) ]; then \
		echo "Error: Vault password file not found at $(VAULT_PASS_FILE)"; \
		echo "Run 'make vault' first"; \
		exit 1; \
	fi
	@ansible-playbook -i $(INVENTORY_FILE) $(PLAYBOOK_FILE) --vault-password-file $(VAULT_PASS_FILE)

clean:
	@if [ -f $(VAULT_PASS_FILE) ]; then \
		rm -f $(VAULT_PASS_FILE); \
		echo "✓ Vault password file $(VAULT_PASS_FILE) removed"; \
	else \
		echo "Vault password file not found"; \
	fi
