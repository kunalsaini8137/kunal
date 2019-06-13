package kunalsaini;
import java.util.Scanner;
public class Leagueoflegends 
{
	public static void main(String args[])
	{
		String c;
		System.out.println("enter your main champion of league:");
		Scanner lol=new Scanner(System.in);
		c=lol.nextLine();
		if(c.equalsIgnoreCase("yasuo"))
		{
		 System.out.println("Passive abilities::\nIntent: Yasuo's critical strike chance is doubled,"
		 		+ "\nbut the damage dealt by his critical strikes is reduced by 10%."
		 		+ "\nResolve: Yasuo gains Flow as he moves – the faster he moves, the faster his Flow meter fills."
		 		+ "\nWhen full, Yasuo activates a brief shield after taking damage from enemy champions or monsters.");
		 System.out.println("Active abilities::\nQ:steel tempest\nW:windwall\nE:sweeping blade\nR:last breath");
		}
		else if(c.equalsIgnoreCase("zed"))
		{
			System.out.println("Passive abilities::\nContempt of the weak::Whenever Zed auto attacks an enemy below 50% Health,"
					+ "\nhe deals an additional 6 / 8 / 10% of their maximum Health as magic damage. The amount is increased at "
					+ "\nlevel 7 and at level 17. This effect cannot occur on the same target more than once every 10 seconds.");
			System.out.println("Active abilities::\nQ:razor shuriken\nW:living shadow\nE:Shadow slash\nR:Death mark");
			}
		else if(c.equalsIgnoreCase("rengar"))
		{
			System.out.println("Passive abilities::\nUnseen predator::While in brush, basic attacking causes Rengar to leap towards"
					+ "\nhis target. Leaping to enter combat generates 1 Ferocity. At 4 Ferocity his next ability is empowered. "
					+ "\nCasting an empowered ability grants 30 / 40 / 50% (at levels 1 / 7 / 13) bonus movement speed for 1.5 seconds."
					+ "\nWhenever a unique champion is killed within 1.5 seconds of taking damage from him, Rengar's attack damage"
					+ "\nis permanently increased");
			System.out.println("Active abilities::\nQ:Savagery\nW:Battle roar\nE:Bola strike\nR:Thrill of the Hunt");
		}
		else if(c.equalsIgnoreCase("garen"))
		{
			System.out.println("Passive abilities::\nPERSEVERANCE::Garen regenerates 2 / 8% of his maximum health per 5 "
					+ "\nseconds after not receiving damage for 9 / 4 seconds (at levels 1/11). The regeneration increases "
					+ "\nto 4 / 16% maximum health per 5 seconds when Garen is below 25 / 50% health (at levels 1/11). Until "
					+ "\nlevel 11, the regenerative state will stop if Garen receives damage from any source other than lane"
					+ "\nminions. After that, Perseverance is also no longer removed by non-epic monsters.");
			System.out.println("\"Active abilities::" + 
					"\nQ:DECISIVE STRIKE" + 
					"\nW:COURAGE"+ 
					"\nE:JUDGMENT" + 
					"\nR:DEMACIAN JUSTICE");
		}
		else if(c.equalsIgnoreCase("darius"))
		{
			System.out.println("Passive abilities::\nHEMORRHAGE::Darius aims his attacks strategically, causing his target to "
					+ "\nbleed for 12 (+1 per champion level) (+0.3 per bonus attack damage) physical damage over 5 seconds."
					+ "\nThis effect stacks up to five times.\n" + 
					"Reaching 5 stacks or killing an enemy champion with Noxian Guillotine activates Noxian Might for 5 seconds."
					+ "\nDuring Noxian Might, Darius gains 30-230 (based on level) bonus Attack Damage and applies max Hemorrhage "
					+ "\nstacks to enemies with basic attacks or Decimate's blade.");
			System.out.println("Active abilities::" + 
					"\nQ:DECIMATE" + 
					"\nW:CRIPPLING STRIKE" + 
					"\nE:APPREHEND" + 
					"\nR:NOXIAN GUILLOTINE");
			}
		
		else if(c.equalsIgnoreCase("ashe"))
		{
			System.out.println("Passive abilities::\nFROST SHOT::Ashe's basic attacks and damaging abilities apply Frost,"
					+ "\nslowing targets by 15-30% (at levels 1-18, increasing every 3 levels) for 2 seconds and causing"
					+ "\nsubsequent basic attacks against them to deal 10 (+ critical strike chance × (1 + bonus critical damage))%"
					+ "\nbonus physical damage while they remain slowed.Ashe's Critical Strikes deal 100% of her total attack damage"
					+ "\n(instead of 200%), but double the effectiveness of Frost Shot, decaying down to the normal slow over 1 second.");
			System.out.println("\"Active abilities::" + 
					"\nQ:RANGER'S FOCUS" + 
					"\nW:VOLLEY ASHE" + 
					"\nE:HAWKSHOT" + 
					"\nR:ENCHANTED CRYSTAL ARROW");
			}
		else 
		{
			System.out.println("KHELNA SEEKHLO CHUTIYO HAHAHAHAHA");
		}
	}
	
}
