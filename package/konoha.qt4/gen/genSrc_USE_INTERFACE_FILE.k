using konoha.xml.*;
using konoha.posix.*;

GEN_CPP_SRC = true;
GEN_ENUM_BIND = true;
OUTPUT_ALL_METHODS = true;
OUTPUT_EVENT_BIND = true;
GEN_CONCATENATE_FILE = true;

include "gen/config.k";
include "gen/script/constStringList.k";
include "gen/script/EnumInterface.k";
include "gen/script/QtXmlReader.k";
include "gen/script/QtInterface.k";
include "gen/script/bind.k";
include "gen/script/FunctionElement.k";
include "gen/script/BindInfo.k";
include "gen/script/makeQtInterface.k";
include "gen/script/makeBindInfo.k";
include "gen/script/event.k";
include "gen/script/genHierarchy.k";
include "gen/script/output.k";
//include "gen/script/genMake.k";
include "gen/script/genCMake.k";

void concatenateHpp(BindInfo[] bia, InputStream ins, boolean use_order_file)
{
	String all_class_decralation = "";
	String qt_headers = "";
	String[] kq_headers = [];

	if (use_order_file) {
		foreach (String line in ins) {
			kq_headers <<< "include/K" + line + ".hpp";
//			qt_headers += "#include <" + line + ">\n";
			all_class_decralation += "class " + line + ";\n";
			all_class_decralation += "class Dummy" + line + ";\n";
		}
	} else {
		int class_count = 0;
		foreach (BindInfo bi in bia) {
			if (bi.checkUnusedClass()) class_count++;
		}

		order_ous = new OutputStream("gen/script/concatenate_order");

		for (int depth = 1; class_count != |bia|; depth++) {
			foreach (BindInfo bi in bia) {
				if (bi.checkUnusedClass()) continue;
				if (bi.hierarchy_depth != depth) continue;
				if (bi.class_name == "") {
					print bi;
					continue;
				}
				kq_headers <<< "include/K" + bi.class_name + ".hpp";
//				qt_headers += "#include <" + bi.class_name + ">\n";
				all_class_decralation += "class " + bi.class_name + ";\n";
				all_class_decralation += "class Dummy" + bi.class_name + ";\n";
				order_ous.println(bi.class_name);
				class_count++;
			}
		}
		order_ous.flush();
		order_ous.close();
	}
	hpp_ous = new OutputStream(CONCATENATE_HPP_FILE);
	hpp_ous.println("#include <qt4_common.hpp>\n");
	hpp_ous.println(qt_headers);
	hpp_ous.println(all_class_decralation);
	hpp_ous.flush();
	hpp_ous.close();
	foreach (header in kq_headers) {
		System.exec("cat " + header +  " >> " + CONCATENATE_HPP_FILE);
	}
}

void concatenateCpp()
{
	cpp_ous = new OutputStream(CONCATENATE_CPP_FILE);
	cpp_ous.println(ConcatenateCppPreface());
//	System.exec("cat src/* >> " + CONCATENATE_CPP_FILE);
	cpp_ous.println(System.exec("cat src/*"));
	cpp_ous.println("#ifdef __cplusplus\n}\n#endif");
	cpp_ous.flush();
	cpp_ous.close();
}

void concatenate(BindInfo[] bia, InputStream ins, boolean use_order_file)
{
	if (!GEN_CONCATENATE_FILE) {
		return;
	}
	print "concatenate";
	String src_path = "src/";
	Dir src_dir = System.openDir(src_path);
	if (src_path == null) {
		print "error in concatinate: src directory not found!!";
		return;
	}
	String include_path = "include/";
	Dir include_dir = System.openDir(include_path);
	if (include_dir == null) {
		print "error in concatinate: moc directory not found!!";
		return;
	}

	if (use_order_file) {
		concatenateHpp([], ins, use_order_file);
	} else {
		concatenateHpp(bia, ins, use_order_file);
	}
	concatenateCpp();
}

void main()
{
	// ins = new InputStream("gen/script/concatenate_order");
	// if (ins != null) {
	// 	print "!!!";
	// 	concatenate([], ins, true);
	// } else {
	QtHierarchy hierarchy = new QtHierarchy();
	QtInterface[] interfaces = makeQtInterface(QT_DOC_DIR, hierarchy);
	if (|interfaces| == 0) {
		print "makeInterface error";
		return;
	}
	BindInfo[] bia = makeBindInfo(interfaces, hierarchy);
//	int event_mtd_num =	genEventSource(bia, interfaces);
	concatenate(bia, null, false);
//	}
	print "exit nomally";
}
