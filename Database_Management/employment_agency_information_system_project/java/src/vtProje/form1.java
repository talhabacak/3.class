package vtProje;

import java.io.IOException;
import java.sql.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.border.EmptyBorder;
import javax.swing.table.DefaultTableModel;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.AbstractButton;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JTabbedPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import java.awt.Color;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JCheckBox;
import javax.swing.JLayeredPane;
import java.awt.Component;
import javax.swing.border.LineBorder;
import javax.swing.border.CompoundBorder;
import javax.swing.border.BevelBorder;
import javax.swing.SwingConstants;
import javax.swing.border.SoftBevelBorder;

public class form1 extends JFrame {

	private JPanel contentPane;
	private JTextField insertValues;
	private JTextField updateSet;
	private JTextField updateWhere;
	private JTextField deleteWhere;
	private final DefaultTableModel viewInter;
	private JTextField textField_Yas;
	private JTextField textField_Mb;
	private JTextField textField_Cursor;
	private final DefaultTableModel rec;
	private final DefaultTableModel cur;
	private final DefaultTableModel having;
	private final DefaultTableModel fonk;
	private JTextField textField_Record;
	private JTextField textField_Fonk;
	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args/*Connection conn*/){
		EventQueue.invokeLater(new Runnable() {
			public void run() {
			        
				try {
					form1 frame = new form1();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public form1() {
		setTitle("Isci Bulma Kurumu Bilgi Sistemi");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 931, 770);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Tablo Sec:");
		lblNewLabel.setForeground(Color.BLACK);
		lblNewLabel.setBackground(Color.BLACK);
		lblNewLabel.setBounds(386, 63, 62, 16);
		contentPane.add(lblNewLabel);
		
		JComboBox tableSec = new JComboBox();
		tableSec.setBackground(Color.LIGHT_GRAY);
		tableSec.setBounds(386, 92, 138, 22);
		contentPane.add(tableSec);
		tableSec.setModel(new DefaultComboBoxModel(new String[] {"Applications", "Postings", "Seekers", "Companies"}));
		
		JTabbedPane tabbedPane = new JTabbedPane(JTabbedPane.TOP);
		tabbedPane.setBorder(new LineBorder(new Color(0, 0, 0)));
		tabbedPane.setBounds(10, 24, 359, 143);
		contentPane.add(tabbedPane);
		
		JPanel panel = new JPanel();
		panel.setBorder(new LineBorder(new Color(0, 0, 0)));
		panel.setBackground(Color.LIGHT_GRAY);
		tabbedPane.addTab("Insert", null, panel, null);
		panel.setLayout(null);
		
		JLabel lblValues = new JLabel("VALUES : (");
		lblValues.setBounds(12, 13, 63, 16);
		panel.add(lblValues);
		
		insertValues = new JTextField();
		insertValues.setColumns(10);
		insertValues.setBounds(87, 10, 210, 22);
		panel.add(insertValues);
		
		
		JCheckBox chckbxSequence = new JCheckBox("Sequence");
		chckbxSequence.setBackground(Color.GRAY);
		chckbxSequence.setBounds(97, 40, 113, 25);
		panel.add(chckbxSequence);
		
		JLabel lblValues_1 = new JLabel(")");
		lblValues_1.setBounds(309, 13, 13, 16);
		panel.add(lblValues_1);
		
		JButton btnEkle = new JButton("Ekle");
		btnEkle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				ekle(tableSec,chckbxSequence);
			}
		});
		
		btnEkle.setBounds(245, 70, 97, 25);
		panel.add(btnEkle);

		
		JPanel panel_1 = new JPanel();
		panel_1.setBorder(new LineBorder(new Color(0, 0, 0)));
		panel_1.setBackground(Color.LIGHT_GRAY);
		tabbedPane.addTab("Update", null, panel_1, null);
		panel_1.setLayout(null);
		
		JLabel lblSet = new JLabel("SET :");
		lblSet.setBounds(12, 13, 40, 16);
		panel_1.add(lblSet);
		
		JLabel lblWhere = new JLabel("WHERE :");
		lblWhere.setBounds(12, 42, 57, 16);
		panel_1.add(lblWhere);
		
		updateSet = new JTextField();
		updateSet.setColumns(10);
		updateSet.setBounds(49, 10, 210, 22);
		panel_1.add(updateSet);
		
		updateWhere = new JTextField();
		updateWhere.setColumns(10);
		updateWhere.setBounds(75, 39, 210, 22);
		panel_1.add(updateWhere);
		
		JButton btnUpdate = new JButton("G\u00FCncelle");
		btnUpdate.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				guncelle(tableSec);
			}
		});
		btnUpdate.setBounds(245, 70, 97, 25);
		panel_1.add(btnUpdate);
		
		JPanel panel_2 = new JPanel();
		panel_2.setBorder(new LineBorder(new Color(0, 0, 0)));
		panel_2.setBackground(Color.LIGHT_GRAY);
		tabbedPane.addTab("Delete", null, panel_2, null);
		panel_2.setLayout(null);
		
		deleteWhere = new JTextField();
		deleteWhere.setColumns(10);
		deleteWhere.setBounds(87, 13, 210, 22);
		panel_2.add(deleteWhere);
		
		JLabel lblWhere_1 = new JLabel("WHERE :");
		lblWhere_1.setBackground(Color.DARK_GRAY);
		lblWhere_1.setBounds(12, 16, 63, 16);
		panel_2.add(lblWhere_1);
		
		JButton btnSil = new JButton("Sil");
		btnSil.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				sil(tableSec);
			}
		});
		btnSil.setBounds(245, 70, 97, 25);
		panel_2.add(btnSil);
		
		JButton btnView = new JButton("View Cagir");
		btnView.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				view();
			}
		});
		btnView.setBounds(132, 306, 97, 25);
		contentPane.add(btnView);
		
		
		Object[] columnNamesViewInter = {"tckn","name","expected_salary","age"};
		viewInter = new DefaultTableModel(columnNamesViewInter, 0);
		JTable tableViewInter = new JTable(viewInter);
		tableViewInter.setBorder(new LineBorder(new Color(0, 0, 0)));
		tableViewInter.setBackground(Color.WHITE);
		tableViewInter.setBounds(12, 411, 323, 299);
		contentPane.add(tableViewInter);
		
		JScrollPane spViewInter = new JScrollPane(tableViewInter);
		spViewInter.setViewportBorder(new LineBorder(new Color(0, 0, 0)));
		spViewInter.setBounds(12, 411, 323, 299);
		contentPane.add(spViewInter);
		
		JButton btnInter = new JButton("Intersect");
		btnInter.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				inter();
			}
		});
		btnInter.setBounds(132, 344, 97, 25);
		contentPane.add(btnInter);
		
		textField_Yas = new JTextField();
		textField_Yas.setColumns(10);
		textField_Yas.setBounds(59, 376, 50, 22);
		contentPane.add(textField_Yas);
		
		textField_Mb = new JTextField();
		textField_Mb.setColumns(10);
		textField_Mb.setBounds(244, 376, 77, 22);
		contentPane.add(textField_Mb);
		
		JLabel lblYas = new JLabel("Ya\u015F :");
		lblYas.setBounds(12, 382, 39, 16);
		contentPane.add(lblYas);
		
		JLabel lblMaasBeklentisi = new JLabel("Maa\u015F Beklentisi :");
		lblMaasBeklentisi.setBounds(132, 382, 97, 16);
		contentPane.add(lblMaasBeklentisi);
		
		JButton btnCursor = new JButton("Cursor");
		btnCursor.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Cursor();
			}
		});
		btnCursor.setBounds(735, 344, 97, 25);
		contentPane.add(btnCursor);
		
		JLabel lblCursor = new JLabel("Cinsiyet (K,E) :");
		lblCursor.setBounds(681, 379, 113, 16);
		contentPane.add(lblCursor);
		
		textField_Cursor = new JTextField();
		textField_Cursor.setColumns(10);
		textField_Cursor.setBounds(795, 376, 77, 22);
		contentPane.add(textField_Cursor);
		
		Object[] columnNamesCursor = {"avgsalary"};
		cur = new DefaultTableModel(columnNamesCursor, 0);
		JTable tableCursor = new JTable(cur);
		tableCursor.setBorder(new LineBorder(new Color(0, 0, 0)));
		tableCursor.setBackground(Color.WHITE);
		tableCursor.setBounds(656, 411, 234, 78);
		contentPane.add(tableCursor);
		
		JScrollPane spCursor = new JScrollPane(tableCursor);
		spCursor.setViewportBorder(new LineBorder(new Color(0, 0, 0)));
		spCursor.setBounds(656, 411, 234, 78);
		contentPane.add(spCursor);
		
		Object[] columnHaving = {"name", "posting_count"};
		having = new DefaultTableModel(columnHaving, 0);
		JTable tableHaving = new JTable(having);
		tableHaving.setBorder(new LineBorder(new Color(0, 0, 0)));
		tableHaving.setBackground(Color.WHITE);
		tableHaving.setBounds(656, 561, 245, 149);
		contentPane.add(tableHaving);
		
		JScrollPane spHaving = new JScrollPane(tableHaving);
		spHaving.setViewportBorder(new LineBorder(new Color(0, 0, 0)));
		spHaving.setBounds(656, 561, 245, 149);
		contentPane.add(spHaving);
		
		JButton btnHaving = new JButton("Aggregate");
		btnHaving.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				aggregate();
			}
		});
		btnHaving.setBounds(735, 523, 97, 25);
		contentPane.add(btnHaving);
		
		Object[] columnRecord = {"raise_expected_salary"};
		rec = new DefaultTableModel(columnRecord, 0);
		JTable tableRecord = new JTable(rec);
		tableRecord.setBorder(new LineBorder(new Color(0, 0, 0)));
		tableRecord.setBackground(Color.WHITE);
		tableRecord.setBounds(368, 411, 245, 299);
		contentPane.add(tableRecord);
		
		JScrollPane spRecord = new JScrollPane(tableRecord);
		spRecord.setViewportBorder(new LineBorder(new Color(0, 0, 0)));
		spRecord.setBounds(368, 411, 245, 299);
		contentPane.add(spRecord);
		
		JButton btnRecord = new JButton("Record");
		btnRecord.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Record();
			}
		});
		btnRecord.setBounds(440, 344, 97, 25);
		contentPane.add(btnRecord);
		
		textField_Record = new JTextField();
		textField_Record.setColumns(10);
		textField_Record.setBounds(490, 376, 77, 22);
		contentPane.add(textField_Record);
		
		JLabel lblRecord = new JLabel("Zam Orani :");
		lblRecord.setBounds(411, 379, 77, 16);
		contentPane.add(lblRecord);
		
		Object[] columnFonk = {"max_salary"};
		fonk = new DefaultTableModel(columnFonk, 0);
		JTable tableFonk = new JTable(fonk);
		tableFonk.setBorder(new LineBorder(new Color(0, 0, 0)));
		tableFonk.setBackground(Color.LIGHT_GRAY);
		tableFonk.setBounds(656, 241, 234, 78);
		contentPane.add(tableFonk);
		
		JScrollPane spFonk = new JScrollPane(tableFonk);
		spFonk.setViewportBorder(new LineBorder(new Color(0, 0, 0)));
		spFonk.setBounds(656, 241, 234, 78);
		contentPane.add(spFonk);
		
		JLabel lblFonk = new JLabel("Pozisyon :");
		lblFonk.setBounds(681, 209, 62, 16);
		contentPane.add(lblFonk);
		
		textField_Fonk = new JTextField();
		textField_Fonk.setColumns(10);
		textField_Fonk.setBounds(755, 206, 117, 22);
		contentPane.add(textField_Fonk);
		
		JButton btnFonk = new JButton("Fonksiyon");
		btnFonk.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				F();
			}
		});
		btnFonk.setBounds(735, 170, 97, 25);
		contentPane.add(btnFonk);
				
	}
	
	
	public static Connection connect() {
		Connection conn = null;
		String user, pass;
	    user = "postgres";
	    pass = "15241524";
	    try {
			conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/proje", user,pass);
	    } catch (SQLException e1) {
			e1.printStackTrace();
		}
		return conn;
	}
	
	private void ekle(JComboBox tableSec, AbstractButton chckbxSequence) { 
		String ins1 = insertValues.getText();
		String ins2 = tableSec.getSelectedItem().toString();
		String ins3 = " ";
		if(chckbxSequence.isSelected()) {
			ins3 = " , nextval('SEQ_POSTING_ID')";
		}
		String ins ="INSERT INTO " + ins2 + " VALUES (" + ins3 + ins1 + ")";
		System.out.println(ins);
		Connection c = form1.connect();
		try {	
			Statement st = c.createStatement();
			st.executeUpdate(ins);
			System.out.println(st.getWarnings());
            st.close();
            c.close();
		}catch (SQLException e) {
			e.printStackTrace();
		}			
	}

	private void guncelle(JComboBox tableSec) { 
		String upd1 = updateWhere.getText();
		String upd2 = updateSet.getText();
		String upd3 = tableSec.getSelectedItem().toString();
		String upd ="UPDATE " + upd3 + " SET " + upd2 + " WHERE " + upd1;
		
		Connection c = form1.connect();
		try {	
			Statement st = c.createStatement();
			st.executeUpdate(upd);
			System.out.println(st.getWarnings());
            st.close();
            c.close();
		}catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	private void sil(JComboBox tableSec) { 
		String del1 = deleteWhere.getText();
		String del2 = tableSec.getSelectedItem().toString();
		String del ="DELETE FROM " + del2 + " WHERE " + del1;
		
		Connection c = form1.connect();
		try {	
			Statement st = c.createStatement();
			st.executeUpdate(del);
			System.out.println(st.getWarnings());
            st.close();
            c.close();
		}catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	private void view() { 
		String view = "SELECT * FROM SEEKERS_AGE";
		
		Connection c = form1.connect();			
		Statement st;
		try {
			st = c.createStatement();
			ResultSet rs = st.executeQuery(view);
			
			viewInter.setRowCount(0);
			
			while(rs.next()) {
				String tckn = rs.getString(1);
        		String name = rs.getString(2);
        		String expected_salary = rs.getString(3);
        		String age = rs.getString(4);
        		
        		Object[] satir ={tckn,name,expected_salary,age};
        		viewInter.addRow(satir);
			}
            st.close();
            c.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	private void inter() {
		String inter1 = textField_Yas.getText();
		String inter2 = textField_Mb.getText();
		String inter = "SELECT * FROM SEEKERS_AGE WHERE AGE > " + inter1 + " AND expected_salary < " + inter2 + " INTERSECT SELECT * FROM SEEKERS_AGE WHERE tckn IN (SELECT seeker_tckn FROM APPLICATIONS)";
		 
		Connection c = form1.connect();			
		Statement st;
		try {
			st = c.createStatement();
			ResultSet rs = st.executeQuery(inter);
			viewInter.setRowCount(0);
			
			while(rs.next()) {
				String tckn = rs.getString(1);
				String name = rs.getString(2);
				String expected_salary = rs.getString(3);
        		String age = rs.getString(4);
        		
        		Object[] satir ={tckn,name,expected_salary,age};
        		viewInter.addRow(satir);
			}
            st.close();
            c.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	private void Record() {
		String Rec1 =  textField_Record.getText();
		String Rec = "SELECT raise_expected_salary(" + Rec1 + ");"; 


		Connection c = form1.connect();			
		Statement st;
		try {
			st = c.createStatement();
			ResultSet rs = st.executeQuery(Rec);
			rec.setRowCount(0);
	
			while(rs.next()) {	
				String raise_expected_salary = rs.getString(1);
	        		
				Object[] satir ={raise_expected_salary};
				rec.addRow(satir);
			}
			st.close();
			c.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	private void aggregate() {
		String agg = "SELECT tbl2.name, \n" + 
						"		tbl1.posting_count \n" + 
						"FROM (\n" + 
						"	SELECT company_vkn, \n" + 
						"			COUNT(*) AS posting_count \n" + 
						"	FROM POSTINGS \n" + 
						"	GROUP BY company_vkn \n" + 
						"	HAVING COUNT(*) > 1 \n" + 
						") tbl1 \n" + 
						"INNER JOIN COMPANIES tbl2 \n" + 
						"ON tbl1.company_vkn = tbl2.vkn;";
		
		Connection c = form1.connect();			
		Statement st;
		try {
			st = c.createStatement();
			ResultSet rs = st.executeQuery(agg);
			
			having.setRowCount(0);
			
			while(rs.next()) {
				String name = rs.getString(1);
				String posting_count = rs.getString(2);
			        		
        		Object[] satir ={name, posting_count};
        		having.addRow(satir);
			}
            st.close();
            c.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	private void Cursor() {
		String Cur1 =  textField_Cursor.getText();
		String Cur = "SELECT avgsalary('" + Cur1 + "');"; 


		Connection c = form1.connect();			
		Statement st;
		try {
			st = c.createStatement();
			ResultSet rs = st.executeQuery(Cur);
	
			cur.setRowCount(0);
	
			while(rs.next()) {	
				String avgsalary = rs.getString(1);
	        		
				Object[] satir ={avgsalary};
				cur.addRow(satir);
			}
			st.close();
			c.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
	
	private void F() {
		String f1 =  textField_Fonk.getText();
		String f = "SELECT find_max_salary_by_position('" + f1 + "');"; 


		Connection c = form1.connect();			
		Statement st;
		try {
			st = c.createStatement();
			ResultSet rs = st.executeQuery(f);
	
			fonk.setRowCount(0);
	
			while(rs.next()) {	
				String max_salary = rs.getString(1);
	        		
				Object[] satir ={max_salary};
				fonk.addRow(satir);
			}
			st.close();
			c.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
}
