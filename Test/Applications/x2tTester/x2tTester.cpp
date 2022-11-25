#include "x2tTester.h"
#include "../../../X2tConverter/src/run.h"

class CFormatsList;
class Cx2tTester;
class CConverter;

CFormatsList::CFormatsList()
{
}

std::vector<int> CFormatsList::GetDocuments() const
{
	return m_documents;
}
std::vector<int> CFormatsList::GetPresentations() const
{
	return m_presentations;
}
std::vector<int> CFormatsList::GetSpreadsheets() const
{
	return m_spreadsheets;
}
std::vector<int> CFormatsList::GetCrossplatform() const
{
	return m_crossplatform;
}
std::vector<int> CFormatsList::GetImages() const
{
	return m_images;
}
int CFormatsList::GetPdf() const
{
	return m_pdf;
}

bool CFormatsList::isDocument(int format) const
{
	return std::find(m_documents.begin(), m_documents.end(), format) != m_documents.end();
}
bool CFormatsList::isPresentation(int format) const
{
	return std::find(m_presentations.begin(), m_presentations.end(), format) != m_presentations.end();
}
bool CFormatsList::isSpreadsheet(int format) const
{
	return std::find(m_spreadsheets.begin(), m_spreadsheets.end(), format) != m_spreadsheets.end();
}
bool CFormatsList::isCrossplatform(int format) const
{
	return std::find(m_crossplatform.begin(), m_crossplatform.end(), format) != m_crossplatform.end();
}
bool CFormatsList::isImage(int format) const
{
	return std::find(m_images.begin(), m_images.end(), format) != m_images.end();
}
bool CFormatsList::isPdf(int format) const
{
	return format == m_pdf;
}

void CFormatsList::SetDefault()
{
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOCX);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOC);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_ODT);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_RTF);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_TXT);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_HTML);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_MHT);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_EPUB);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_FB2);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_MOBI);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOCM);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOTX);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOTM);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_ODT_FLAT);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOC_FLAT);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOCX_FLAT);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_HTML_IN_CONTAINER);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOCX_PACKAGE);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_OTT);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_OFORM);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOCXF);

	m_presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_PPTX);
	m_presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_PPT);
	m_presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_ODP);
	m_presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_PPSX);
	m_presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_PPTM);
	m_presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_PPSM);
	m_presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_POTX);
	m_presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_POTM);
	m_presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_ODP_FLAT);
	m_presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_OTP);
	m_presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_PPTX_PACKAGE);

	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLSX);
	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLS);
	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_ODS);
	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_CSV);
	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLSM);
	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLTX);
	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLTM);
	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLSB);
	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_ODS_FLAT);
	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_OTS);
	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLSX_FLAT);
	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLSX_PACKAGE);

	m_crossplatform.push_back(AVS_OFFICESTUDIO_FILE_CROSSPLATFORM_DJVU);
	m_crossplatform.push_back(AVS_OFFICESTUDIO_FILE_CROSSPLATFORM_XPS);

	m_images.push_back(AVS_OFFICESTUDIO_FILE_IMAGE_JPG);
	m_images.push_back(AVS_OFFICESTUDIO_FILE_IMAGE_PNG);

	m_pdf = AVS_OFFICESTUDIO_FILE_CROSSPLATFORM_PDF;
}

void CFormatsList::SetOutput()
{
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOCX);
//	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOC);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_ODT);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_RTF);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_TXT);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_HTML);
//	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_MHT);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_EPUB);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_FB2);
//	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_MOBI);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOCM);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOTX);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOTM);
//	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_ODT_FLAT);
//	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOC_FLAT);
//	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOCX_FLAT);
//	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_HTML_IN_CONTAINER);
//	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOCX_PACKAGE);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_OTT);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_OFORM);
	m_documents.push_back(AVS_OFFICESTUDIO_FILE_DOCUMENT_DOCXF);

	m_presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_PPTX);
//	m_presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_PPT);
	m_presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_ODP);
	m_presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_PPSX);
	m_presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_PPTM);
	m_presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_PPSM);
	m_presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_POTX);
	m_presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_POTM);
//	m_presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_ODP_FLAT);
	m_presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_OTP);
//	presentations.push_back(AVS_OFFICESTUDIO_FILE_PRESENTATION_PPTX_PACKAGE);

	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLSX);
//	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLS);
	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_ODS);
	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_CSV);
	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLSM);
	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLTX);
	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLTM);
//	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLSB);
//	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_ODS_FLAT);
	m_spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_OTS);
//	spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLSX_FLAT);
//	spreadsheets.push_back(AVS_OFFICESTUDIO_FILE_SPREADSHEET_XLSX_PACKAGE);

	m_crossplatform.push_back(AVS_OFFICESTUDIO_FILE_CROSSPLATFORM_DJVU);
	m_crossplatform.push_back(AVS_OFFICESTUDIO_FILE_CROSSPLATFORM_XPS);

	m_images.push_back(AVS_OFFICESTUDIO_FILE_IMAGE_JPG);
	m_images.push_back(AVS_OFFICESTUDIO_FILE_IMAGE_PNG);

	m_pdf = AVS_OFFICESTUDIO_FILE_CROSSPLATFORM_PDF;
}
std::vector<int> CFormatsList::allFormats() const
{
	std::vector<int> all_formats;

	for(auto val : m_documents)
		all_formats.push_back(val);

	for(auto val : m_presentations)
		all_formats.push_back(val);

	for(auto val : m_spreadsheets)
		all_formats.push_back(val);

	for(auto val : m_images)
		all_formats.push_back(val);

	for(auto val : m_crossplatform)
		all_formats.push_back(val);

	all_formats.push_back(m_pdf);

	return all_formats;
}

void WaitDirectory(const std::wstring& path, const bool& exist_check = true)
{
	while (exist_check != NSDirectory::Exists(path))
		NSThreads::Sleep(10);
}
void WaitFile(const std::wstring& path, const bool& exist_check = true)
{
	while (exist_check != NSFile::CFileBinary::Exists(path))
		NSThreads::Sleep(10);
}

Cx2tTester::Cx2tTester(const std::wstring& configPath)
{
	m_bIsUseSystemFonts = true;
	m_bIsErrorsOnly = false;
	m_bIsTimestamp = true;
	m_bIsDeleteOk = false;
	m_inputFormatsList.SetDefault();
	m_outputFormatsList.SetOutput();
	setConfig(configPath);
	m_errorsXmlDirectory = m_outputDirectory + L"/_errors";

	if(m_bIsTimestamp)
	{
		time_t now = time(0);
		std::tm* time = std::localtime(&now);
		std::wstring timestamp =
				std::to_wstring(time->tm_mday) + L"_" +
				std::to_wstring(time->tm_mon + 1) + L"_" +
				std::to_wstring(time->tm_year + 1900) + L"_" +
				std::to_wstring(time->tm_hour) + L"_" +
				std::to_wstring(time->tm_min) + L"_" +
				std::to_wstring(time->tm_sec);

		std::wstring report_ext = NSFile::GetFileExtention(m_reportFile);
		m_reportFile = m_reportFile.substr(0, m_reportFile.size() - report_ext.size() - 1);
		m_reportFile += L"_" + timestamp + L"." + report_ext;
	}

	if(NSFile::CFileBinary::Exists(m_reportFile))
		NSFile::CFileBinary::Remove(m_reportFile);

	if(!m_reportStream.CreateFileW(m_reportFile))
	{
		std::cerr << "Report file is not open!" << std::endl;
		exit(-1);
	}

	m_coresCS.InitializeCriticalSection();
	m_reportCS.InitializeCriticalSection();
	m_outputCS.InitializeCriticalSection();
	m_utilsCS.InitializeCriticalSection();

	m_currentProc = 0;
	writeReportHeader();
}
Cx2tTester::~Cx2tTester()
{
	m_coresCS.DeleteCriticalSection();
	m_reportCS.DeleteCriticalSection();
	m_outputCS.DeleteCriticalSection();
	m_utilsCS.DeleteCriticalSection();

	m_reportStream.CloseFile();
}

void Cx2tTester::setConfig(const std::wstring& configPath)
{
	bool default_input_formats = true;
	bool default_output_formats = true;

	XmlUtils::CXmlNode root;
	XmlUtils::CXmlNodes nodes;
	if(root.FromXmlFile(configPath) && root.GetChilds(nodes))
	{
		for(int i = 0; i < nodes.GetCount(); i++)
		{
			XmlUtils::CXmlNode node;
			nodes.GetAt(i, node);
			std::wstring name = node.GetName();

			// key-value
			if(name == L"reportPath") m_reportFile = node.GetText();
			else if(name == L"inputDirectory") m_inputDirectory = node.GetText();
			else if(name == L"outputDirectory") m_outputDirectory = node.GetText();
			else if(name == L"x2tPath") m_x2tPath = node.GetText();
			else if(name == L"cores") m_maxProc = std::stoi(node.GetText());
			else if(name == L"errorsOnly") m_bIsErrorsOnly = std::stoi(node.GetText());
			else if(name == L"timestamp") m_bIsTimestamp = std::stoi(node.GetText());
			else if(name == L"deleteOk") m_bIsDeleteOk = std::stoi(node.GetText());
			else if(name == L"inputFilesList")
			{
				XmlUtils::CXmlNode files_list_root;
				XmlUtils::CXmlNodes files_list_nodes;

				std::wstring files_list = node.GetText();
				if(files_list_root.FromXmlFile(files_list) && files_list_root.GetChilds(files_list_nodes))
				{
					for(int j = 0; j < files_list_nodes.GetCount(); j++)
					{
						XmlUtils::CXmlNode n;
						files_list_nodes.GetAt(j, n);
						m_inputFiles.push_back(n.GetText());
					}
				}
				else
				{
					std::cerr << "Input files list is not open!" << std::endl;
				}
			}
			else if(name == L"input")
			{
				default_input_formats = false;
				std::wstring extensions = node.GetText();
				extensions += L' ';
				m_inputFormats = parseExtensionsString(extensions, m_inputFormatsList);
			}
			else if(name == L"output")
			{
				default_output_formats = false;
				std::wstring extensions = node.GetText();
				extensions += L' ';
				m_outputFormats = parseExtensionsString(extensions, m_outputFormatsList);
			}
			else if (name == L"fonts")
			{
				m_bIsUseSystemFonts = (1 == node.ReadAttributeInt(L"system", 1)) ? true : false;
				XmlUtils::CXmlNodes oNodeFontDirs = node.ReadNodesNoNS(L"directory");
				for (int nIndex = 0, nCount = oNodeFontDirs.GetCount(); nIndex < nCount; ++nIndex)
				{
					XmlUtils::CXmlNode oNodeDir;
					oNodeFontDirs.GetAt(nIndex, oNodeDir);
					m_arAdditionalFontsDirs.push_back(oNodeDir.GetText());
				}
			}
		}
	}
	else
	{
		std::cerr << "Config file is not open!" << std::endl;
		exit(-1);
	}

	if(default_input_formats)
		m_inputFormats = m_inputFormatsList.allFormats();

	if(default_output_formats)
		m_outputFormats = m_outputFormatsList.allFormats();


}
void Cx2tTester::Start()
{
	// setup timer
	m_timeStart = NSTimers::GetTickCount();

	// check fonts
	std::wstring fonts_directory = NSFile::GetProcessDirectory() + L"/fonts";
	CApplicationFontsWorker fonts_worker;
	fonts_worker.m_sDirectory = fonts_directory;
	if (!NSDirectory::Exists(fonts_worker.m_sDirectory))
		NSDirectory::CreateDirectory(fonts_worker.m_sDirectory);

	fonts_worker.m_bIsUseSystemFonts = m_bIsUseSystemFonts;

	for (std::vector<std::wstring>::iterator i = m_arAdditionalFontsDirs.begin(); i != m_arAdditionalFontsDirs.end(); i++)
	{
		std::wstring sFolder = *i;
		if (0 == sFolder.find(L"."))
			sFolder = NSFile::GetProcessDirectory() + L"/" + sFolder;
		fonts_worker.m_arAdditionalFolders.push_back(sFolder);
	}

	fonts_worker.m_bIsNeedThumbnails = false;
	NSFonts::IApplicationFonts* pFonts = fonts_worker.Check();
	RELEASEINTERFACE(pFonts);

	// setup & clear output folder
	if(NSDirectory::Exists(m_outputDirectory))
		NSDirectory::DeleteDirectory(m_outputDirectory);

	WaitDirectory(m_outputDirectory, false);

	NSDirectory::CreateDirectory(m_outputDirectory);

	// waiting for directory
	WaitDirectory(m_outputDirectory);

	// setup & clear errors folder
	if(NSDirectory::Exists(m_errorsXmlDirectory))
		NSDirectory::DeleteDirectory(m_errorsXmlDirectory);

	NSDirectory::CreateDirectory(m_errorsXmlDirectory);

	// waiting for directory
	WaitDirectory(m_errorsXmlDirectory);

	std::vector<std::wstring> files = NSDirectory::GetFiles(m_inputDirectory, true);
	for(int i = 0; i < files.size(); i++)
	{
		std::wstring& input_file = files[i];
		std::wstring input_filename = NSFile::GetFileName(input_file);

		std::wstring input_ext = NSFile::GetFileExtention(input_file);
		int input_format = COfficeFileFormatChecker::GetFormatByExtension(L'.' + input_ext);

		// if no format in input formats - skip
		if(std::find(m_inputFormats.begin(), m_inputFormats.end(), input_format) == m_inputFormats.end()
		|| (std::find(m_inputFiles.begin(), m_inputFiles.end(), input_filename) == m_inputFiles.end()
		&& !m_inputFiles.empty()))
		{
			files.erase(files.begin() + i);
			i--;
		}
	}

	if(files.size() < m_maxProc)
		m_maxProc = files.size();

	for(int i = 0; i < files.size(); i++)
	{
		std::wstring& input_file = files[i];

		std::wstring input_ext = NSFile::GetFileExtention(input_file);
		int input_format = COfficeFileFormatChecker::GetFormatByExtension(L'.' + input_ext);

		std::wstring input_file_directory = NSFile::GetDirectoryName(input_file);
		std::wstring output_files_directory = m_outputDirectory;

		// takes full directory after input folder
		std::wstring input_subfolders = input_file_directory.substr(m_inputDirectory.size(),
																	input_file_directory.size() - m_inputDirectory.size());
		output_files_directory += input_subfolders;

		// setup & clear output subfolder
		while(!NSDirectory::Exists(output_files_directory))
		{
			NSDirectory::CreateDirectories(output_files_directory);
			WaitDirectory(output_files_directory);
		}

		output_files_directory += L'/' + NSFile::GetFileName(input_file);

		// setup output_formats for file
		std::vector<int> output_file_formats;

		for(auto format : m_outputFormats)
		{
			// documents -> documents
			if(((m_outputFormatsList.isDocument(format) && m_inputFormatsList.isDocument(input_format))
			// spreadsheets -> spreadsheets
			|| (m_outputFormatsList.isSpreadsheet(format) && m_inputFormatsList.isSpreadsheet(input_format))
			//presentations -> presentations
			|| (m_outputFormatsList.isPresentation(format) && m_inputFormatsList.isPresentation(input_format))
			// crossplatform -> documents
			|| (m_outputFormatsList.isDocument(format) && m_inputFormatsList.isCrossplatform(input_format))
			// pdf -> docx
			|| (format == AVS_OFFICESTUDIO_FILE_DOCUMENT_DOCX && m_inputFormatsList.isPdf(input_format))
			// all formats -> images
			|| m_outputFormatsList.isImage(format)
			// all formats -> pdf
			|| m_outputFormatsList.isPdf(format))
			// input format != output format
			&& format != input_format)
			{
				output_file_formats.push_back(format);
			}
		}

		// setup folder for output files
		if(NSDirectory::Exists(output_files_directory))
			NSDirectory::DeleteDirectory(output_files_directory);

		NSDirectory::CreateDirectory(output_files_directory);

		// waiting
		WaitDirectory(output_files_directory);

		// waiting...
		do
			NSThreads::Sleep(50);
		while(isAllBusy());

		m_coresCS.Enter();

		// setup & start new coverter
		CConverter *converter = new CConverter(this);
		converter->SetInputFile(input_file);
		converter->SetInputFormat(input_format);
		converter->SetOutputFilesDirectory(output_files_directory);
		converter->SetOutputFormats(output_file_formats);
		converter->SetFontsDirectory(fonts_directory);
		converter->SetX2tPath(m_x2tPath);
		converter->SetOnlyErrors(m_bIsErrorsOnly);
		converter->SetDeleteOk(m_bIsDeleteOk);
		converter->SetXmlErrorsDirectory(m_errorsXmlDirectory);
		converter->SetFilesCount(files.size(), i + 1);
		converter->DestroyOnFinish();
		m_currentProc++;

		m_coresCS.Leave();

		converter->Start(0);
	}

	// waiting all procs end
	while(!isAllFree())
		NSThreads::Sleep(150);

	writeTime();
}
void Cx2tTester::writeReportHeader()
{
	CTemporaryCS CS(&m_reportCS);
	m_reportStream.WriteStringUTF8(L"Input file\t", false);
	m_reportStream.WriteStringUTF8(L"Output file\t", true);
	m_reportStream.WriteStringUTF8(L"Time\t", true);
	m_reportStream.WriteStringUTF8(L"Input size\t", true);
	m_reportStream.WriteStringUTF8(L"Output size\t", true);
	m_reportStream.WriteStringUTF8(L"Exit code\t", true);
	m_reportStream.WriteStringUTF8(L"Log\n", true);
}
void Cx2tTester::writeReport(const Report& report)
{
	CTemporaryCS CS(&m_reportCS);

	m_reportStream.WriteStringUTF8(report.inputFile + L"\t", true);
	m_reportStream.WriteStringUTF8(report.outputFile + L"\t", true);
	m_reportStream.WriteStringUTF8(std::to_wstring(report.time) + L"\t", true);
	m_reportStream.WriteStringUTF8(std::to_wstring(report.inputSize) + L"\t", true);
	m_reportStream.WriteStringUTF8(std::to_wstring(report.outputSize) + L"\t", true);
	m_reportStream.WriteStringUTF8(std::to_wstring(report.exitCode) + L"\t", true);
	m_reportStream.WriteStringUTF8(report.log + L"\n", true);
}
void Cx2tTester::writeReports(const std::vector<Report>& reports)
{
	CTemporaryCS CS(&m_reportCS);
	for(auto& report : reports)
	{
		m_reportStream.WriteStringUTF8(report.inputFile + L"\t", true);
		m_reportStream.WriteStringUTF8(report.outputFile + L"\t", true);
		m_reportStream.WriteStringUTF8(std::to_wstring(report.time) + L"\t", true);
		m_reportStream.WriteStringUTF8(std::to_wstring(report.inputSize) + L"\t", true);
		m_reportStream.WriteStringUTF8(std::to_wstring(report.outputSize) + L"\t", true);
		m_reportStream.WriteStringUTF8(std::to_wstring(report.exitCode) + L"\t", true);
		m_reportStream.WriteStringUTF8(report.log + L"\n", true);
	}
}
void Cx2tTester::writeTime()
{
	CTemporaryCS CS(&m_reportCS);
	DWORD time = NSTimers::GetTickCount() - m_timeStart;
	m_reportStream.WriteStringUTF8(L"Time: " + std::to_wstring(time));
}

bool Cx2tTester::isAllBusy()
{
	CTemporaryCS CS(&m_coresCS);
	return m_currentProc == m_maxProc;
}
bool Cx2tTester::isAllFree()
{
	CTemporaryCS CS(&m_coresCS);
	return m_currentProc == 0;
}

std::vector<int> Cx2tTester::parseExtensionsString(std::wstring extensions, const CFormatsList& fl)
{
	std::vector<int> formats;
	int pos = 0;
	while ((pos = extensions.find(' ')) != std::wstring::npos)
	{
		std::wstring ext = extensions.substr(0, pos);

		if(ext == L"documents")
			formats = fl.GetDocuments();

		else if(ext == L"presentations")
			formats = fl.GetPresentations();

		else if(ext == L"spreadsheets")
			formats = fl.GetSpreadsheets();

		else
		{
			int format =  COfficeFileFormatChecker::GetFormatByExtension(L'.' + ext);
			formats.push_back(format);
		}
		extensions.erase(0, pos + 1);
	}
	return formats;
}

CConverter::CConverter(Cx2tTester* internal) : m_internal(internal), m_bIsErrorsOnly(false)
{
}
CConverter::~CConverter()
{
	Stop();
}

void CConverter::SetInputFile(const std::wstring& inputFile)
{
	m_inputFile = inputFile;
}
void CConverter::SetInputFormat(int inputFormat)
{
	m_inputFormat = inputFormat;
}
void CConverter::SetOutputFilesDirectory(const std::wstring& outputFilesDirectory)
{
	m_outputFilesDirectory = outputFilesDirectory;
}
void CConverter::SetOutputFormats(const std::vector<int> outputFormats)
{
	m_outputFormats = outputFormats;
}
void CConverter::SetFontsDirectory(const std::wstring& fontsDirectory)
{
	m_fontsDirectory = fontsDirectory;
}
void CConverter::SetX2tPath(const std::wstring& x2tPath)
{
	m_x2tPath = x2tPath;
}
void CConverter::SetOnlyErrors(bool bIsErrorsOnly)
{
	m_bIsErrorsOnly = bIsErrorsOnly;
}
void CConverter::SetDeleteOk(bool bIsDeleteOk)
{
	m_bIsDeleteOk = bIsDeleteOk;
}
void CConverter::SetXmlErrorsDirectory(const std::wstring& errorsXmlDirectory)
{
	m_errorsXmlDirectory = errorsXmlDirectory;
}
void CConverter::SetFilesCount(int totalFiles, int currFile)
{
	m_totalFiles = totalFiles;
	m_currFile = currFile;
}


DWORD CConverter::ThreadProc()
{
	std::vector<Cx2tTester::Report> reports;

	std::wstring input_filename = NSFile::GetFileName(m_inputFile);
	std::wstring input_ext = NSFile::GetFileExtention(input_filename);
	std::wstring input_filename_no_ext = input_filename.substr(0, input_filename.size() - input_ext.size() - 1);

	DWORD time_file_start = NSTimers::GetTickCount();

	bool is_all_ok = true;

	// input_format in many output exts
	for(int i = 0; i < m_outputFormats.size(); i++)
	{
		int& output_format = m_outputFormats[i];

//		if(m_inputFormat == output_format)
//			continue;

		std::wstring output_ext =  checker.GetExtensionByType(output_format);
		std::wstring xml_params_filename = input_filename + L"_" + output_ext + L".xml";
		std::wstring xml_params_file = m_outputFilesDirectory + L"/" + xml_params_filename;

		std::wstring output_file = m_outputFilesDirectory
				+ L"/" + input_filename_no_ext + output_ext;

		std::wstring output_filename = NSFile::GetFileName(output_file);

		// creating temporary xml file with params
		NSStringUtils::CStringBuilder builder;
		builder.WriteString(L"<?xml version=\"1.0\" encoding=\"utf-8\"?>");

		builder.WriteString(L"<Root>");

		builder.WriteString(L"<m_sFileFrom>");
		builder.WriteEncodeXmlString(m_inputFile);
		builder.WriteString(L"</m_sFileFrom>");

		builder.WriteString(L"<m_sFileTo>");
		builder.WriteEncodeXmlString(output_file);

		if (output_format & AVS_OFFICESTUDIO_FILE_IMAGE)
			builder.WriteEncodeXmlString(L".zip");

		builder.WriteString(L"</m_sFileTo>");

		builder.WriteString(L"<m_nFormatTo>");
		if (output_format & AVS_OFFICESTUDIO_FILE_IMAGE)
			builder.WriteString(std::to_wstring(AVS_OFFICESTUDIO_FILE_IMAGE));
		else
			builder.WriteString(std::to_wstring(output_format));
		builder.WriteString(L"</m_nFormatTo>");

		builder.WriteString(L"<m_sThemeDir>./</m_sThemeDir>");
		builder.WriteString(L"<m_bDontSaveAdditional>true</m_bDontSaveAdditional>");

		builder.WriteString(L"<m_sAllFontsPath>");
		builder.WriteEncodeXmlString(m_fontsDirectory + L"/AllFonts.js");
		builder.WriteString(L"</m_sAllFontsPath>");

		builder.WriteString(L"<m_sFontDir>");
		builder.WriteEncodeXmlString(m_fontsDirectory);
		builder.WriteString(L"</m_sFontDir>");

		if (output_format & AVS_OFFICESTUDIO_FILE_IMAGE)
		{
			builder.WriteString(L"<m_oThumbnail><format>");
			if (AVS_OFFICESTUDIO_FILE_IMAGE_JPG == output_format)
				builder.WriteString(L"3");
			else
				builder.WriteString(L"4");
			builder.WriteString(L"</format><aspect>2</aspect><first>false</first><width>1000</width><height>1000</height></m_oThumbnail>");
		}

		builder.WriteString(L"<m_sJsonParams>{&quot;spreadsheetLayout&quot;:{&quot;gridLines&quot;:true,&quot;headings&quot;:true,&quot;fitToHeight&quot;:1,&quot;fitToWidth&quot;:1,&quot;orientation&quot;:&quot;landscape&quot;}}</m_sJsonParams>");

		builder.WriteString(L"</Root>");

		std::wstring xml_params = builder.GetData();
		NSFile::CFileBinary::SaveToFile(xml_params_file, xml_params, true);

		// waiting
		WaitFile(xml_params_file);

		int exit_code = NSX2T::Convert(NSFile::GetDirectoryName(m_x2tPath), xml_params_file);

		int input_size = 0;
		int output_size = 0;

		NSFile::CFileBinary b_file;

		b_file.OpenFile(m_inputFile);
		input_size = b_file.GetFileSize();
		b_file.CloseFile();

		if (!exit_code)
		{
			if(output_format & AVS_OFFICESTUDIO_FILE_IMAGE)
				b_file.OpenFile(output_file + L".zip");
			else
				b_file.OpenFile(output_file);

			output_size = b_file.GetFileSize();
			b_file.CloseFile();
		}

		if (!exit_code && output_format & AVS_OFFICESTUDIO_FILE_IMAGE)
		{
			NSDirectory::CreateDirectory(output_file);

			// waiting
			WaitDirectory(output_file);

			m_internal->m_utilsCS.Enter();

			COfficeUtils oUtils;

			if (S_OK == oUtils.ExtractToDirectory(output_file + L".zip", output_file, NULL, 0))
				NSFile::CFileBinary::Remove(output_file + L".zip"); 

			m_internal->m_utilsCS.Leave();
		}

		// save param xml of error conversion
		if(exit_code)
		{
			std::wstring err_xml_file = m_errorsXmlDirectory + L"/" + xml_params_filename;
			NSFile::CFileBinary::SaveToFile(err_xml_file, xml_params, true);
		}

		// writing report
		if(!m_bIsErrorsOnly || exit_code)
		{
			Cx2tTester::Report report;
			report.inputFile = input_filename;
			report.outputFile = output_filename;
			report.time = NSTimers::GetTickCount() - time_file_start;
			report.inputSize = input_size;
			report.outputSize = output_size;
			report.exitCode = exit_code;
			report.log = xml_params;
			reports.push_back(report);
		}

		NSFile::CFileBinary::Remove(xml_params_file);

		std::string input_file_UTF8 = U_TO_UTF8(input_filename);
		std::string output_file_UTF8 = U_TO_UTF8(output_filename);

		// output_CS start
		m_internal->m_outputCS.Enter();

		std::cout << "[" << m_currFile << "/" << m_totalFiles << "](" << i + 1 << "/" << m_outputFormats.size() << ") ";
		std::cout << "(" << m_internal->m_currentProc << " processes now) ";
		std::cout << input_file_UTF8 << " to " << output_file_UTF8 << " ";

		if(!exit_code)
		{
			std::cout << "OK ";
		}
		else
		{
			is_all_ok = false;
			std::cout << "BAD ";
		}

		std::cout << std::endl;
		m_internal->m_outputCS.Leave();

		if(m_bIsDeleteOk && !exit_code)
		{
			NSFile::CFileBinary::Remove(output_file);

			// waiting
			WaitFile(output_file, false);
		}
	}
	m_internal->writeReports(reports);

	if(m_bIsDeleteOk && is_all_ok)
	{
		NSDirectory::DeleteDirectory(m_outputFilesDirectory);

		// waiting
		WaitDirectory(m_outputFilesDirectory, false);
	}

	CTemporaryCS CS(&m_internal->m_coresCS);
	m_internal->m_currentProc--;

	return 0;
}


