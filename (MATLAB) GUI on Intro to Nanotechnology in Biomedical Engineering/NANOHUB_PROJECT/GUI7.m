%Designed by Apoorv Gaur
function varargout = GUI7(varargin)
% GUI7 MATLAB code for GUI7.fig
%      GUI7, by itself, creates a new GUI7 or raises the existing
%      singleton*.
%
%      H = GUI7 returns the handle to a new GUI7 or the handle to
%      the existing singleton*.
%
%      GUI7('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI7.M with the given input arguments.
%
%      GUI7('Property','Value',...) creates a new GUI7 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before GUI7_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to GUI7_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help GUI7

% Last Modified by GUIDE v2.5 23-Apr-2013 21:48:11

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @GUI7_OpeningFcn, ...
                   'gui_OutputFcn',  @GUI7_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before GUI7 is made visible.
function GUI7_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to GUI7 (see VARARGIN)

% Choose default command line output for GUI7
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);
set (handles.descrip,'String','Nanomedical approaches to drug delivery center on developing nanoscale particles or molecules to improve drug bioavailability. ');
set (handles.link_biom,'String','Bioavailability refers to the presence of drug molecules where they are needed in the body and where they will do the most good. Drug delivery focuses on maximizing bioavailability both at specific places in the body and over a period of time.');
set (handles.link_ss,'String','Molecular targeting by nanoengineered devices: It is all about targeting the molecules and delivering drugs with cell precision, which requires accurate vision to the nanoscale level.');
set (handles.image_h,'String','Drug Delivery');
a=imread('Drug_Delivery.png'); 
image(a);  
axis off
% UIWAIT makes GUI7 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = GUI7_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in toLast.
function toLast_Callback(hObject, eventdata, handles)
% hObject    handle to toLast (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close
GUI6

% --- Executes on button press in nexSlide.
function nexSlide_Callback(hObject, eventdata, handles)
% hObject    handle to nexSlide (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in ovSlide.
function ovSlide_Callback(hObject, eventdata, handles)
% hObject    handle to ovSlide (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in homeSlide.
function homeSlide_Callback(hObject, eventdata, handles)
% hObject    handle to homeSlide (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in toHome.
function toHome_Callback(hObject, eventdata, handles)
% hObject    handle to toHome (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close
nanohubGUI_sec008_team24

% --- Executes on button press in toOv.
function toOv_Callback(hObject, eventdata, handles)
% hObject    handle to toOv (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close
overviewGUI_sec008_team24

% --- Executes on button press in toNext.
function toNext_Callback(hObject, eventdata, handles)
% hObject    handle to toNext (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close
GUI8

% --- Executes on selection change in pop.
function pop_Callback(hObject, eventdata, handles)
% hObject    handle to pop (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns pop contents as cell array
%        contents{get(hObject,'Value')} returns selected item from pop

%get what the user chooses
val = get(hObject,'Value');

% Set current data to the selected data set.
switch val;
case 1 % User selects drug delivery.
   set (handles.descrip,'String','Nanomedical approaches to drug delivery center on developing nanoscale particles or molecules to improve drug bioavailability. ');
   set (handles.link_biom,'String','Bioavailability refers to the presence of drug molecules where they are needed in the body and where they will do the most good. Drug delivery focuses on maximizing bioavailability both at specific places in the body and over a period of time.');
   set (handles.link_ss,'String','Molecular targeting by nanoengineered devices: It is all about targeting the molecules and delivering drugs with cell precision, which requires accurate vision to the nanoscale level.');
   set (handles.image_h,'String','Drug Delivery');
   a=imread('Drug_Delivery.png'); 
   image(a);  
   axis off
case 2 % User selects Molecular Imaging.
   set (handles.descrip,'String','Molecular imaging originated from the field of radiopharmacology due to the need to better understand the fundamental molecular pathways inside organisms in a noninvasive manner.');
   set (handles.link_biom,'String','Molecular Imaging enables the visualisation of the cells in living organisms. It helps in diagnosis of diseases such as cancer, neurological and cardiovascular diseases. It contributes to the treatment of these disorders by optimizing tests of new medication.');
   set (handles.link_ss,'String','Biomarkers (Chemical Stimulants) interact chemically with their surroundings and in turn alter the image according to molecular changes occurring within the area of interest. Noticing these changes to the minute levels requires the understanding of Size and Scale.');
   set (handles.image_h,'String','Molecular Imaging');
   a=imread('Molecular_Imaging.png'); 
   image(a);  
   axis off
case 3 % User selects Microfluids.
   set (handles.descrip,'String','Microfluidics deals with the behavior, precise control and manipulation of fluids that are geometrically constrained to a small, typically sub-millimeter, scale.');
   set (handles.link_biom,'String','Fluids are moved, mixed, separated or otherwise processed. Biomedical Engineering professes passive fluid control techniques like capillary forces. In some applications external actuation means are additionally used for a directed transport of the media.');
   set (handles.link_ss,'String','Precise control and manipulation of fluids at a small sub-millimeter scale requires powerful equipment that can notice fluctuations at a nano-scale level.');
   set (handles.image_h,'String','Drug Delivery');
   a=imread('Micro_fluids.png'); 
   image(a);  
   axis off
case 4 % User selects Cell Arrays.
   set (handles.descrip,'String','High-density ordered array involving either living cells (microwells) or printed microarrays (slides).');
   set (handles.link_biom,'String','It involves reading frames of the genes printed at high density on a slide along with a reagent. It is placed in a cell culture plate, the cells grow on top of the DNA spots and drive the expression of specific proteins. This would a typical study in Biomedical Engineering.');
   set (handles.link_ss,'String','Study of Cell-Array require the study of DNA spots, which require a precision down to 10^-9 to 10^-10 level. (Nano Scale Level)');
   set (handles.image_h,'String','Cell Arrays');
   a=imread('Cell_Arrays.png'); 
   image(a);  
   axis off
case 5 % User selects 2D and 3D ECMs and Patterning
   set (handles.descrip,'String','In vivo cells primarily exist embedded within a complex and information-rich environment that contains multiple extracellular matrix (ECM) components, in both 2D and 3D dimensions.');
   set (handles.link_biom,'String','Many cell types become flatter, divide aberrantly and lose their differentiated phenotype. Some of these cell types can regain their physiological form and function when embedded in a 3D culture environment. This would a typical study in Biomedical Engineering.');
   set (handles.link_ss,'String','Molecular targeting by nanoengineered devices: It is all about targeting the molecules and delivering drugs with cell precision, which requires accurate vision to the nanoscale level.');
   set (handles.image_h,'String','ECM Patterning');
   a=imread('2D_3D.png'); 
   image(a);  
   axis off
end

% --- Executes during object creation, after setting all properties.
function pop_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pop (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
