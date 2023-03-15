import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class CryptoManagerTestStudent {

	@BeforeEach
	void setUp() throws Exception {
	}

	@AfterEach
	void tearDown() throws Exception {
	}

	@Test
	void testIsStringInBounds() {
		assertTrue(CryptoManager.isStringInBounds("THIS TEST SHOULD PASS"));
	}

	@Test
	void testCaesarEncryption() {
		assertEquals("#T\"#/\"#!X]V", CryptoManager.caesarEncryption("TEST STRING", 15));
	}

	@Test
	void testBellasoEncryption() {
		assertEquals("P&3QDPR3LV#[TKRPV", CryptoManager.bellasoEncryption("MY NAME IS NAHOMI", "CMSCC"));
	}

	@Test
	void testCaesarDecryption() {
		assertEquals("TEST STRING", CryptoManager.caesarDecryption("#T\"#/\"#!X]V", 15));
	}

	@Test
	void testBellasoDecryption() {
		assertEquals("MY NAME IS NAHOMI", CryptoManager.bellasoDecryption("P&3QDPR3LV#[TKRPV", "CMSCC"));

	}

}
