import static org.junit.Assert.assertTrue;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class GradeBookTest {
	GradeBook gb1;
	GradeBook gb2;

	@BeforeEach
	void setUp() throws Exception {
		gb1= new GradeBook(5);
		gb2=new GradeBook(5);
		gb1.addScore(59);
		gb1.addScore(95);
		gb2.addScore(77);
		gb2.addScore(60);

		
	}

	@AfterEach
	void tearDown() throws Exception {	
		gb1=null;
		gb2=null;
		
	}

	@Test
	void testAddScore() {
		assertEquals(2, gb1.getScoreSize(),2);
		assertTrue(gb1.toString().equals("59.0 95.0 "));
		assertEquals(2, gb2.getScoreSize(),2);
		assertTrue(gb2.toString().equals("77.0 60.0 "));
		
	}

	@Test
	void testSum(){
		assertEquals(154,gb1.sum(),154);
		assertEquals(137,gb2.sum(),137);

	}

	@Test
	void testMinimum() {
		assertEquals(59, gb1.minimum(),59);
		assertEquals(60, gb2.minimum(),60);
	}

	@Test
	void testFinalScore() {
		assertEquals(95, gb1.finalScore(), 95);
		assertEquals(77, gb1.finalScore(), 77);
	}

	

}
